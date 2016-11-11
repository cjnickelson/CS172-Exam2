//I affirm that all code given below was written solely by me, Carter Nickelson, and that any help I received
//adhered to the rules stated for this exam.

#pragma once
#include<string>
#include"Citizen.h"

using namespace std;

// class definition for city
class City
{
	string cityName;
	int population;
	vector<Citizen*> citizenList;
public:
	City(string);
	~City();
	string getCityName();
	int populationSize();
	Citizen* getCitizenAtIndex(int);
	void addCitizen(Citizen*);
	Citizen* getCitizenWithID(int);
	vector<Citizen*> getCitizensForFavoriteColor(string);
};