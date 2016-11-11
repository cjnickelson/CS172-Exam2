//I affirm that all code given below was written solely by me, Carter Nickelson, and that any help I received
//adhered to the rules stated for this exam.

#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

// class definition for citizen
class Citizen
{
	int id;
	string firstName, lastName, favoriteColor;
public:
	Citizen(int, string, string, string);
	Citizen(Citizen*);
	string getFirstName();
	string getLastName();
	int getID();
	string getFavoriteColor();
	void setFavoriteColor(string);
};