//I affirm that all code given below was written solely by me, Carter Nickelson, and that any help I received
//adhered to the rules stated for this exam.

#include"Citizen.h"

// constructor for a new citizen, taking arguments for eac of the member variables id, first and last names, and favorite color
Citizen::Citizen(int ID, string fn, string ln, string fc)
{
	id = ID;
	firstName = fn;
	lastName = ln;
	favoriteColor = fc;
}
// constructor for a new citizen copying the information from another citizen. 
Citizen::Citizen(Citizen* cit)
{
	// uses each get function to set the new citizen's member variables to those of the old one's
	id = cit->getID();
	firstName = cit->getFirstName();
	lastName = cit->getLastName();
	favoriteColor = cit->getFavoriteColor();
}

// all get functions perform the typical function, returning their respective values

string Citizen::getFirstName()
{
	return firstName;
}
string Citizen::getLastName()
{
	return lastName;
}
int Citizen::getID()
{
	return id;
}
string Citizen::getFavoriteColor()
{
	return favoriteColor;
}
// takes input from the user and changes a citizen's favorite color
void Citizen::setFavoriteColor(string color)
{
	favoriteColor = color;
}