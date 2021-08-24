/*
Name: Aldalton Choo Chien Khin
Student ID: 101212783
Date: 15-05-2021
Project Description: Read values of five variables required by the decision tree from a text file and predict the root cause of overhead line tripping.
Then write the values of five variables for each overhead line tripping incident into the corresponding root cause file based on the root cause predicted by the decision tree.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "overheadLineTrippingObject.h"

using namespace std;

void getFileName(string& fileName); //function prototype for getFileName
void getData(string& fileName, ifstream& infile, vector<string>& data); // function prototype for getData
void checkRootCause(string e_fault, double v_gradient, double v_dip, string p_fault, double v_timeinterval, int& current_transformer_explosion_count, int& tree_encroachment_counter, int& crane_counter, int& pollution_counter, int& light_strike_counter);//function prototype for checkRootCause
void writeRootCause(ofstream& outfile, string e_fault, double v_gradient, double v_dip, string p_fault, double v_timeinterval); //prototype function for writeRootCause
void resetFileData(); // prototype function for resetFileData
void outputResult(int current_transformer_explosion_count, int tree_encroachment_counter, int crane_counter, int pollution_counter, int light_strike_counter);//prototype function for outputResult

int main()
{
	string fileName;
	vector<string> data;
	vector<overheadLineTrippingObject> oObjectList; //create vector object to store the variables obtained
	
	ifstream infile; //reading data from txt file
	ofstream outfile; //writing data to appropriate root cause txt file

	int counter = 1; //keep track of index in data vector to store data into the oObjectList
	int objectcounter = 0; //keep track of object


	//counter for each causing variable starts here
	int current_transformer_explosion_count = 0;
	int tree_encroachment_counter = 0;
	int crane_counter = 0;
	int pollution_counter = 0;
	int lightning_strike_counter = 0;

	getFileName(fileName);
	getData(fileName, infile, data);

	for (int i = 0; i < data.size(); i++) //function to store the variable from data vector into oObject vector
	{

		if (counter == 1) 
		{
			overheadLineTrippingObject oObject;
			oObject.seteFault(data[i]);
			oObjectList.push_back(oObject);
			counter++;
		}
		else if (counter == 2)
		{
			oObjectList[objectcounter].setvGradient(stod(data[i]));
			counter++;
		}
		else if (counter == 3)
		{
			oObjectList[objectcounter].setvDip(stod(data[i]));
			counter++;
		}
		else if (counter == 4)
		{
			oObjectList[objectcounter].setpFault(data[i]);
			counter++;
		}
		else if (counter == 5)
		{
			oObjectList[objectcounter].settInterval(stod(data[i]));
			objectcounter++;
			counter = 1;
		}
		

	}

	//used to reset the txt file every it is open so that previous data is not stored when the program is run
	resetFileData();
	

	for (int j = 0; j < oObjectList.size();j++)
	{
		checkRootCause(oObjectList[j].geteFault(), oObjectList[j].getvGradient(), oObjectList[j].getvDip(), oObjectList[j].getpFault(), oObjectList[j].gettInterval(), current_transformer_explosion_count, tree_encroachment_counter, crane_counter, pollution_counter, lightning_strike_counter);	
		writeRootCause(outfile, oObjectList[j].geteFault(), oObjectList[j].getvGradient(), oObjectList[j].getvDip(), oObjectList[j].getpFault(), oObjectList[j].gettInterval());
	}

	outputResult(current_transformer_explosion_count, tree_encroachment_counter, crane_counter, pollution_counter, lightning_strike_counter);

	

}

void getFileName(string& fileName) //function to get the user input for file name
{
	cout << "Please enter the file name you wish to retrieve the five variables required by the decision tree from: ";
	cin >> fileName;
	return;

}

void getData(string& fileName, ifstream& infile, vector<string>& data) //function to get the data based on the file name that the user has input
{
	infile.open(fileName);

	if (infile.fail())
	{
		cout << "File reading error";
		exit(1);
	}

	string temp;
	do
	{
		infile >> temp;
		if (infile.good())
		{
			data.push_back(temp);
		}

	} while (infile.good());

	infile.close();

	return;
}

void checkRootCause(string e_fault,double v_gradient,double v_dip,string p_fault,double v_timeinterval ,int& current_transformer_explosion_count,int& tree_encroachment_counter,int& crane_counter,int& pollution_counter,int& light_strike_counter) //function to check through the variables to determine which root cause that cause the overheadline to trip
{
	if (e_fault == "yes")
	{
		current_transformer_explosion_count++;
	}
	else
	{
		if (v_gradient < 0.100)
		{
			tree_encroachment_counter++;
		}
		else 
		{
			if (v_dip <= 0.100)
			{
				tree_encroachment_counter++;
			}
			else 
			{
				if (p_fault == "yes")
				{
					crane_counter++;
				}
				else
				{
					if (v_timeinterval >= 100)
					{
						pollution_counter++;
					}
					else
					{
						light_strike_counter++;
					}
				}
			}
		}

	}

	return;
}

void writeRootCause(ofstream& outfile, string e_fault, double v_gradient, double v_dip, string p_fault, double v_timeinterval) //function to write the variables to the appropriate root cause txt file that cause the overheadline to trip
{
	if (e_fault == "yes")
	{
		ofstream outfile;
		outfile.open("ctexplod.txt", std::ios_base::app);
		if (outfile.is_open())
		{
			outfile << e_fault << " " << v_gradient << " " << v_dip << " " << p_fault << " " << v_timeinterval << endl;
			outfile.close();
		}
		else
		{
			cout << "unable to open file";
		}
		
		//current_transformer_explosion_count++;
	}
	else
	{
		if (v_gradient < 0.100)
		{
			ofstream outfile;
			outfile.open("treeencr.txt", std::ios_base::app);

			if (outfile.is_open())
			{
				outfile << e_fault << " " << v_gradient << " " << v_dip << " " << p_fault << " " << v_timeinterval << endl;
				outfile.close();
			}
			else
			{
				cout << "unable to open file";
			}
			
			//tree_encroachment_counter++;
		}
		else
		{
			if (v_dip <= 0.100)
			{
				ofstream outfile;
				outfile.open("treeencr.txt", std::ios_base::app);
				if (outfile.is_open())
				{
					outfile << e_fault << " " << v_gradient << " " << v_dip << " " << p_fault << " " << v_timeinterval << endl;
					outfile.close();
					
				}
				else
				{
					cout << "unable to open file";
				}
				//tree_encroachment_counter++;
			}
			else
			{
				if (p_fault == "yes")
				{
					ofstream outfile;
					outfile.open("crane.txt", std::ios_base::app);
					if (outfile.is_open())
					{
						outfile << e_fault << " " << v_gradient << " " << v_dip << " " << p_fault << " " << v_timeinterval << endl;
						outfile.close();
					}
					else
					{
						cout << "unable to open file";
					}
					//crane_counter++;
				}
				else
				{
					if (v_timeinterval >= 100)
					{
						ofstream outfile;
						outfile.open("pollut.txt", std::ios_base::app);
						if (outfile.is_open())
						{
							outfile << e_fault << " " << v_gradient << " " << v_dip << " " << p_fault << " " << v_timeinterval << endl;
							outfile.close();
						}
						else
						{
							cout << "unable to open file";
						}
						//pollution_counter++;
					}
					else
					{
						
						ofstream outfile;
						outfile.open("lightnin.txt", std::ios_base::app);
						if (outfile.is_open())
						{
							outfile << e_fault << " " << v_gradient << " " << v_dip << " " << p_fault << " " << v_timeinterval << endl;
							outfile.close();
						}
						else
						{
							cout << "unable to open file";
						}
						//light_strike_counter++;
					}
				}
			}
		}

	}

	return;
}

void resetFileData()
{
	ofstream ctfile;
	ctfile.open("ctexplod.txt");
	ctfile.close();

	ofstream treefile;
	treefile.open("treeencr.txt");
	treefile.close();

	ofstream cranefile;
	cranefile.open("crane.txt");
	cranefile.close();

	ofstream pollutfile;
	pollutfile.open("pollut.txt");
	pollutfile.close();

	ofstream lightninfile;
	lightninfile.open("lightnin.txt");
	lightninfile.close();
}

void outputResult(int current_transformer_explosion_count, int tree_encroachment_counter, int crane_counter, int pollution_counter, int light_strike_counter)//function to output the number of count for each root cause
{
	cout << "Current Transfomer Explosion Count: " << current_transformer_explosion_count << endl;
	cout << "Tree Encroachment Count: " << tree_encroachment_counter << endl;
	cout << "Crane Count: " << crane_counter << endl;
	cout << "Pollution Count: " << pollution_counter << endl;
	cout << "Lightning Strike Count: " << light_strike_counter;
}







