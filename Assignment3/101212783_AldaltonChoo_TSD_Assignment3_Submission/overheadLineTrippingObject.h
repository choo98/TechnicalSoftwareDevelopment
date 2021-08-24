#pragma once
#include <iostream>
using namespace std;

class overheadLineTrippingObject
{
private:
	string eFault;
	double vGradient;
	double vDip;
	string pFault;
	double tInterval;

public:
	overheadLineTrippingObject(); //default constructor for overheadlinetrippingobject

	void seteFault(string efault); //getter setter for eFault
	string geteFault();

	void setvGradient(double vgradient);//getter setter for vGradient
	double getvGradient();

	void setvDip(double vdip);//getter setter for vDip
	double getvDip();

	void setpFault(string pfault); //getter setter for pFault
	string getpFault();

	void settInterval(double tinterval);//getter setter for tInterval
	double gettInterval();



	
};

