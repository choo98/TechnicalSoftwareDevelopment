#include "overheadLineTrippingObject.h"

overheadLineTrippingObject::overheadLineTrippingObject()
{
	eFault = "";
	vGradient = 0.0;
	vDip = 0.0;
	pFault = "";
	tInterval = 0.0;
}

void overheadLineTrippingObject::seteFault(string efault)
{
	eFault = efault;
}

string overheadLineTrippingObject::geteFault()
{
	return eFault;
}

void overheadLineTrippingObject::setvGradient(double vgradient)
{
	vGradient = vgradient;
}

double overheadLineTrippingObject::getvGradient()
{
	return vGradient;
}

void overheadLineTrippingObject::setvDip(double vdip)
{
	vDip = vdip;
}

double overheadLineTrippingObject::getvDip()
{
	return vDip;
}

void overheadLineTrippingObject::setpFault(string pfault)
{
	pFault = pfault;
}

string overheadLineTrippingObject::getpFault()
{
	return pFault;
}

void overheadLineTrippingObject::settInterval(double tinterval)
{
	tInterval = tinterval;
}

double overheadLineTrippingObject::gettInterval()
{
	return tInterval;
}
