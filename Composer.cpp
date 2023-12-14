#include "Composer.h"

//Default constructor. Takes nothing, returns nothing
Composer::Composer()
{
	name = "";
	date = 0;
}

//Overloaded Constructor. Returns nothing, takes in a string and integer
Composer::Composer(string n, int d)
{
	name = n;
	date = d;
}

//Overloaded Constructor. Returns nothing, takes in a string
Composer::Composer(string n)
{
	name = n;
	date = 0;
}

//Destructor. Takes nothing, returns nothing. No need to delete (no dynamic)
Composer::~Composer(){}

//Overloaded < operator. Takes constant Composer value by reference.
//Returns boolean and compares if date is less than the date on the right
bool Composer::operator<(const Composer& right) const
{
	if (date < right.date)
		return true;

	return false;
}

//Overloaded >operator. Takes constant Composer value by reference.
//Returns boolean and compares if date is greater than the date on the right
bool Composer::operator>(const Composer& right) const
{
	if (date > right.date)
		return true;

	return false;
}

//Overloaded ==operator. Takes constant Composer value by reference.
//Returns boolean and compares if name is equal to name on the right
bool Composer::operator==(const Composer& right) const
{
	if (name == right.name)
	{
		return true;
	}
	return false;
}

//Overloaded !=operator. Takes constant Composer value by reference.
//Returns boolean to see if name is not equal to name on right
bool Composer::operator!=(const Composer& right) const
{
	return !(name == right.name);
}

//Overloaded <<operator. Takes ostream by reference, constant composer
//by reference. Displays composer object.
ostream& operator<<(ostream& out, const Composer& right)
{
	out << right.name << " - " << right.date << endl;
	return out;
}

