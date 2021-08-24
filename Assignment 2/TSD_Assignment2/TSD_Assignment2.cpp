/*
Name: Aldalton Choo Chien Khin
Student ID: 101212783
Date: 16-04-2021
Project Description: Calculate the amount of rainwater harvested based on user inputs and put it in a table form for the user to see
*/

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

//Recursive function to create the table as shown in the assignment sheet
void recursionTable(double roofStart, double roofEnd, double roofIncrement,double precipitationStart, double precipitationEnd, double precipitationIncrement)
{
	//if statement to make the function return if not will never return
	if (roofStart > roofEnd && precipitationStart > precipitationEnd)
	{
		return ;
	}
	else
	{
		double tempVal = precipitationStart; //stores the temporary value for percipitation start value
		cout << setw(10)<<"";
		for (precipitationStart;precipitationStart < precipitationEnd;precipitationStart += precipitationIncrement)
		{
			//print out the values for precipitation
		
			cout << setw(12);
			cout << setprecision(2) << fixed << precipitationStart << fixed;

		}
		if (precipitationStart >= precipitationEnd)
		{
			//so that the final value is printed out
			precipitationStart = precipitationEnd;

			cout << setw(12);
			cout << setprecision(2) << precipitationStart << fixed;
		}
		
		for(roofStart; roofStart < roofEnd; roofStart+=roofIncrement)
		{
			//print out values for roof area
			if (roofStart <= roofEnd) 
			{
				//makes sure the final value for roof area is printed out
				cout << endl;
				cout << setw(10);
				cout << setprecision(2) << roofStart << fixed;
				for (precipitationStart = tempVal;precipitationStart < precipitationEnd;precipitationStart += precipitationIncrement)
				{
					cout << setw(12);
					cout << setprecision(2) << (precipitationStart * roofStart) << fixed;
				}
				if (precipitationStart >= precipitationEnd)
				{
					//so that final value is printed out
					precipitationStart = precipitationEnd;
					cout << setw(12);
					cout << setprecision(2) << (precipitationStart * roofStart) << fixed;
				}
				
			}
		}
		if (roofStart >= roofEnd)
		{
			//print final value for roof area
			roofStart = roofEnd;
			cout << endl;
			cout << setw(10);
			cout << setprecision(2) << roofStart << fixed;
			for (precipitationStart = tempVal;precipitationStart < precipitationEnd;precipitationStart += precipitationIncrement)
			{
				cout << setw(12);
				cout << setprecision(2) << (precipitationStart * roofStart) << fixed;
			}
			if (precipitationStart >= precipitationEnd)
			{
				//so that final value is printed out
				precipitationStart = precipitationEnd;
				cout << setw(12);
				cout << setprecision(2) << (precipitationStart * roofStart) << fixed;
			}
		}
		
		//calls the function inside the recursive function again
		recursionTable((roofStart + roofIncrement), roofEnd, roofIncrement, (precipitationStart+precipitationIncrement), precipitationEnd, precipitationIncrement);
		return;

	}
}

int main()
{
	double start_roof_area;
	double end_roof_area;
	double start_precipitation_value;
	double end_precipitation_value;
	double incremental_roof_area;
	double incremental_precipitation_value;
	
	do
	{
		//input validation for starting roof area
		cout << "Enter starting roof area in meter square (must be positive): ";
		if (!(cin >> start_roof_area))
		{
			cout << "Invalid input. Please try again" << endl;
			cin.clear();
			cin.ignore(10000000, '\n'); //remove unwanted characters
		}	 
	} while (start_roof_area <= 0);

	do
	{
		//input validation for ending roof area
		cout << "Enter ending roof area in meter square (must be positive): ";
		if (!(cin >> end_roof_area))
		{
			cout << "Invalid input. Please try again" << endl;
			cin.clear();
			cin.ignore(10000000, '\n'); //remove unwanted characters
		}
	} while (end_roof_area <= 0);

	do
	{
		//input validation for roof area incremental
		cout << "Enter incremental value in roof area in meter square (must be positive): ";
		if (!(cin >> incremental_roof_area))
		{
			cout << "Invalid input. Please try again" << endl;
			cin.clear();
			cin.ignore(10000000, '\n'); //remove unwanted characters
		}
	} while (incremental_roof_area <= 0);

	do
	{
		//input validation for starting precipitation value
		cout << "Enter starting value for precipitation in mm (must be positive): ";
		if (!(cin >> start_precipitation_value))
		{
			cout << "Invalid input. Please try again" << endl;
			cin.clear();
			cin.ignore(10000000, '\n'); //remove unwanted characters
		}
	} while (start_precipitation_value <= 0);

	do
	{
		//input validation for ending precipitation value
		cout << "Enter ending value for precipitation in mm (must be positive): ";
		if (!(cin >> end_precipitation_value))
		{
			cout << "Invalid input. Please try again" << endl;
			cin.clear();
			cin.ignore(10000000, '\n'); //remove unwanted characters
		}
	} while (end_precipitation_value <= 0);

	do
	{
		//input validation for roof area incremental
		cout << "Enter incremental value for precipitation value in mm (must be positive): ";
		if (!(cin >> incremental_precipitation_value))
		{
			cout << "Invalid input. Please try again" << endl;
			cin.clear();
			cin.ignore(10000000, '\n'); //remove unwanted characters
		}
	} while (incremental_precipitation_value <= 0);

	//calls the recursive function to build the table by using the input values that the user have entered
	recursionTable(start_roof_area,end_roof_area, incremental_roof_area,start_precipitation_value,end_precipitation_value,incremental_precipitation_value);
	
}


