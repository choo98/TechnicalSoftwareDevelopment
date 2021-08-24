/*TSD_Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
*Programmer: Aldalton Choo Chien Khin
*Date 30-March-2021
*Program description: Technical Software Development Assignment 1 Predicting Root Cause of Overhead Line Tripping
*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	//Variables are declared here
	string e_fault; // store the evolving fault value that the users enter
	string p_fault; // Store the permanent fault value that the users enter
	double v_gradient; //v stands for value and this is to store the value of gradient that users enter
	double v_voltageDip; // store the voltage dip value that the users enter
	double v_timeInterval; // store the time interval between the last neutral current distortions and a flashover
	string retry = "";

	//Start of the program
	while (retry != "no") //cause the program to loop until the user enters no at the end of the program when asked if they want to retry the program.
	{
		//input validation for Evolving fault
		do
		{
			//First decision process starts here
			cout << "Is the evolving fault causing the overhead line tripping? Enter yes or no only: ";
			cin >> e_fault;
			transform(e_fault.begin(), e_fault.end(), e_fault.begin(), ::tolower); // transforms the input from user to lower case to accept both capital letters and non-capital letters
			if (e_fault != "yes" && e_fault != "no")
			{
				cout << "Invalid input. Only yes or no is accepted. Please try again" << endl;
				cin.clear();
				cin.ignore(10000000, '\n'); //remove unwanted characters
			}
		} while (e_fault != "yes" && e_fault != "no");

		if (e_fault == "yes")
		{
			cout << "It is the evolving fault that caused a CT explosion to happen thus causing the overhead line to trip" << endl;
			cout << "program will now end";
			return 0;
		}
		else
		{
			do
			{
				//Second decision process starts here
				cout << "It is not the evolving fault. What is the gradient value? Enter numbers only: ";
				//Validate gradient input
				if (!(cin >> v_gradient))
				{
					cout << "Invalid input. Only numbers are accepted. Please try again" << endl;
					cin.clear();
					cin.ignore(10000000, '\n'); //remove unwanted characters
				}
				else if (v_gradient <= 0) //will not accept negative values and zero as a value
				{
					cout << "Only positive numbers allowed and value bigger than zero allowed" << endl;
					cin.clear();
					cin.ignore(10000000, '\n'); //remove unwanted characters
				}
			} while (v_gradient <= 0);

			if (v_gradient >= 0.100)
			{
				do
				{
					//3rd decision process starts here
					cout << "It is not the rate of change of curve (gradient) at fault. What is the voltage dip value? Enter numbers only: ";
					//Validate voltage dip input
					if (!(cin >> v_voltageDip))//validate input to accept numbers only
					{
						cout << "Invalid input. Only numbers are accepted. Please try again" << endl;
						cin.clear();
						cin.ignore(10000000, '\n'); //remove unwanted characters
					}
					else if (v_voltageDip <= 0)//will not accept negative values and zero as a value
					{
						cout << "Only positive numbers allowed and value bigger than zero allowed" << endl;
						cin.clear();
						cin.ignore(10000000, '\n'); //remove unwanted characters
					}
				} while (v_voltageDip <= 0);

				if (v_voltageDip <= 0.100)
				{
					cout << "A tree encroachment has happen thus causing the overhead line to trip" << endl;
					cout << "program will now end";
					return 0;
				}
				else
				{
					//input validation for permanent fault
					do
					{
						//4th decision process starts here
						cout << "It is not the voltage dip at fault.Is a permanent fault causing the overhead line tripping? Enter yes or no only: ";
						cin >> p_fault;
						transform(p_fault.begin(), p_fault.end(), p_fault.begin(), ::tolower); // transforms the input from user to lower case to accept both capital letters and non-capital letters
						if (p_fault != "yes" && p_fault != "no")
						{
							cout << "Invalid input. Only yes or no is accepted. Please try again" << endl;
							cin.clear();
							cin.ignore(10000000, '\n'); //remove unwanted characters
						}
					} while (p_fault != "yes" && p_fault != "no");

					if (p_fault == "yes")
					{
						cout << "The crane caused the overhead line to trip" << endl;
						cout << "program will now end";
						return 0;
					}
					else
					{
						do
						{
							//5th decision process starts here
							cout << "It is not a permanent fault. What is the time interval between the last neutral current distortions and a flashover (ms) ? Enter numbers only: ";
							//Validate time interval input
							if (!(cin >> v_timeInterval))//validate input to accept numbers only
							{
								cout << "Invalid input. Only numbers are accepted. Please try again" << endl;
								cin.clear();
								cin.ignore(10000000, '\n'); //remove unwanted characters
							}
							else if (v_timeInterval <= 0)//will not accept negative values and zero as a value
							{
								cout << "Only positive numbers allowed and value bigger than zero allowed" << endl;
								cin.clear();
								cin.ignore(10000000, '\n'); //remove unwanted characters
							}
						} while (v_timeInterval <= 0);

						if (v_timeInterval >= 100)
						{
							cout << "Pollution caused the overhead line to trip" << endl;
						}
						else
						{
							cout << "Lightning strike caused the overhead line to trip" << endl;
						}

						//Option to give user a retry starts here
						do
						{
							cout << endl << "Would you like to try again?: ";
							cin >> retry;
							transform(retry.begin(), retry.end(), retry.begin(), ::tolower); // transforms the input from user to lower case to accept both capital letters and non-capital letters
							if (retry != "yes" && retry != "no")
							{
								cout << "Invalid input. Only yes or no is accepted. Please try again" << endl;
								cin.clear();
								cin.ignore(10000000, '\n'); //remove unwanted characters
							}
							
						} while (retry != "yes" && retry != "no"); //ensure that user can only enter yes or no
					}
				}
			}
			else
			{
				cout << "A tree encroachment has happen thus causing the overhead line to trip" << endl;
				cout << "program will now end";
				return 0;
			}
		}
	}
	//Ends the program when user enters no
	cout << "Program will now end. Thanks for participating." << endl;
	return 0;
}