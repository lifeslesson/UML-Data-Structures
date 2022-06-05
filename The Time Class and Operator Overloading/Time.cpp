/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Time.cpp: Time function definitions
 * Includes blank definitions for overloaded operators to be written for Program 3
 */

#include "Time.h"	   // Necessary for Time class definition; implicitly includes <iostream>
#include <iomanip>	// Necessary for setw(), setfill()
using std::setw;
using std::setfill;

/*** OVERLOADED OPERATORS TO BE ADDED FOR PROGRAM 3 ***/
/*** PREVIOUSLY DEFINED FUNCTIONS START ON LINE 145 (BEFORE YOU START ADDING CODE) ***/
/*** UPDATED 10/11 TO FIX PARAMETERIZED CONSTRUCTOR, advance() ***/

// Output operator
ostream& operator <<(ostream& out, const Time& rhs) {

	/*************************************************
	* Print time using form:
	*    h:mm _M  or hh:mm _M
	* where:
	*    h or hh	= # of hours (1 or 2 digits)
	*    mm			= # of minutes (always 2 digits)
	*    _M			= AM or PM
	**************************************************/

	// set the clock to 12 midnight from military time to normal people time
	out << rhs.hours << ':' << setw(2) << setfill('0') << rhs.minutes
		<< ' ' << rhs.AMorPM << 'M';

	return out;

}

// Input operator
istream& operator >>(istream& in, Time& rhs) {

	/*************************************************
	* Read time assuming it is written in form:
	*    h:mm _M  or hh:mm _M
	* where:
	*    h or hh	= # of hours (1 or 2 digits)
	*    mm			= # of minutes (always 2 digits)
	*    _M			= AM or PM
	**************************************************/
	in >> setw(2) >> rhs.hours;
	in.ignore(1, ':');
	in >> setw(2) >> rhs.minutes;
	//in.ignore(1, isspace(in));
	in >> rhs.AMorPM;
	in.ignore(1, 'M');

	return in;

}

// Comparison operators
bool Time::operator ==(const Time& rhs) {

	/********************************************
	* Returns true if calling object matches rhs,
	*   false otherwise
	*********************************************/
	if (hours == rhs.hours && minutes == rhs.minutes && AMorPM == rhs.AMorPM) {
		return false;
	}
	return true;
}

bool Time::operator !=(const Time& rhs) {

	/**************************************************
	* Returns true if calling object doesn't match rhs,
	*   false otherwise
	***************************************************/
	if (hours != rhs.hours && minutes != rhs.minutes && AMorPM != rhs.AMorPM) {
		return false;
	}
	return true;
}

bool Time::operator <(const Time& rhs) {

	/**********************************************
	* Returns true if calling object is less
	*   (earlier in day) than rhs, false otherwise
	***********************************************/
	if (miltime < rhs.miltime) {
		return false;
	}
	return true;
}

bool Time::operator >(const Time& rhs) {

	/********************************************
	* Returns true if calling object is greater
	*   (later in day) than rhs, false otherwise
	*********************************************/
	if (miltime > rhs.miltime) {
		return false;
	}
	return true;
}

// Arithmetic operators
Time Time::operator +(const Time& rhs) {
	int sum;

	/********************************************
	* Add two Time objects and return sum
	*   See examples in spec
	*********************************************/

	hours = hours + rhs.hours;
	minutes = minutes + rhs.minutes;

	sum = (hours * 1000) + minutes;
	//sum.miltime = miltime + miltime;

	return const sum;
}


Time Time::operator -(const Time& rhs) {
	Time diff;

	/*************************************************
	* Subtract two Time objects and return difference
	*   See examples in spec
	**************************************************/

	diff.miltime = (miltime - rhs.miltime);

	return diff;
}

Time& Time::operator +=(const Time& rhs) {

	/**************************************************
	* Same as + operator, but modifies calling object
	*   and returns reference to calling object
	***************************************************/

	this->miltime += rhs.miltime;
}

Time& Time::operator -=(const Time& rhs) {

	/**************************************************
	* Same as - operator, but modifies calling object
	*   and returns reference to calling object
	***************************************************/

	this->miltime -= rhs.miltime;
}

// Increment operators--adds 1 minute to current time
Time& Time::operator++() {
	/*************************
	* Pre-increment operator
	**************************/

	ostream set();
	minutes++;

}

Time Time::operator++(int) {
	/*************************
	* Post-increment operator
	**************************/

	Time m = *this;

	m++;

	return m;

}
/*** END OVERLOADED OPERATORS TO BE ADDED FOR PROGRAM 3 ***/
/*** DO NOT MODIFY CODE BELOW THIS LINE ***/
// Default constructor
Time::Time() : hours(0), minutes(0), miltime(0), AMorPM('A')
{}

// Parameterized constructor
Time::Time(unsigned h, unsigned m, char AP) : hours(h), minutes(m), AMorPM(AP) {
	miltime = 100 * h + m;

	/*** FIXED 10/11: ORIGINAL VERSION DID NOT CORRECTLY HANDLE 12 AM OR 12 PM ***/
	if (AP == 'P' && h != 12)
		miltime += 1200;
	else if (AP == 'A' && h == 12)
		miltime -= 1200;
}

// Set time data members
void Time::set(unsigned h, unsigned m, char AP) {
	hours = h;
	minutes = m;
	AMorPM = AP;
	miltime = 100 * h + m;
	if (AP == 'P')
		miltime += 1200;
}

// Print time to desired output stream
void Time::display(ostream& out) {
	out << hours << ':'
		<< setw(2) << setfill('0') << minutes		// setw(2) forces minutes to be printed with 2 chars
		<< ' ' << AMorPM << 'M';					// setfill('0') adds leading 0 to minutes if needed
}

// Advance time by h hours, m minutes
// Use modulo arithmetic to ensure 
//   1 <= hours <= 12, 0 <= minutes <= 59
/*** FIXED 10/11: ORIGINAL VERSION DIDN'T WORK FOR ALL CASES AND WAS FAR TOO CONVOLUTED ***/
/***  NEW VERSION DOES ALL MATH ON MILTIME AND THEN CORRECTS HOURS, MINUTES ***/
void Time::advance(unsigned h, unsigned m) {

	unsigned tempMT = h * 100 + m;		// Temporary miltime representing amount
												//   of time to advance by, since math
												 //   is much easier using miltime!

	// If sum of minutes >= 60, need to account for extra hour added
	if (minutes + m >= 60)
		miltime = (miltime + tempMT + 40) % 2400;	// % 2400 ensures time between 0 & 2359
															 //   (since minutes adjustment guarantees
															 //    last two digits < 60)
	else
		miltime = (miltime + tempMT) % 2400;

	// Convert back from miltime to new hours/minutes
	hours = miltime / 100;

	// Special case 1: time in PM (other than 12 PM)
	if (hours > 12)
		hours -= 12;

	// Special case 2: 12:xx AM --> miltime / 100 = 0
	else if (hours == 0)
		hours = 12;

	minutes = miltime % 100;

	// Figure out if new time is in AM or PM
	AMorPM = (miltime < 1200 ? 'A' : 'P');
}

// Returns true if calling object is less than argument
bool Time::lessThan(const Time& rhs) {
	if (miltime < rhs.miltime)
		return true;
	else
		return false;
}