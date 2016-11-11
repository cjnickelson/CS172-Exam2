//I affirm that all code given below was written solely by me, Carter Nickelson, and that any help I received
//adhered to the rules stated for this exam.

#include"City.h"

// Constructor with string argument for the name of the city
City::City(string name)
{
	// sets the name of the city to the one from the argument
	cityName = name;
	// sets the population to 0
	population = 0;
	// creates a filename that is just the name of the city followed by .txt
	string filename = name + ".txt";
	// creates an input file stream called file
	ifstream file;
	// opens the file
	file.open(filename);
	// if the file cannot open, the rest of the function should be skipped, as there was no city to begin with, we must be creating a new, and therefore empty, one
	if (!file)
	{
		
	}
	// if the file was opened, a city must have already existed. So retrieve that city's data
	else
	{
		// I had the output print the population to the file first, so we have to get past this by getline, which we will do nothing with
		string populationIgnore;
		getline(file, populationIgnore);
		// while the end of the file has not been reached, continue to read in information
		while (!file.eof())
		{
			// create int variable to hold the id, and strings to hold the first and last names and favorite color
			int ID;
			string fn, ln, fc;
			// read the id in (this will be the first piece of info after the population and will end when the space is reached)
			file >> ID;
			// read in the next pieces of info, the names and favorite color
			file >> fn >> ln >> fc;
			// create a new citizen with these traits
			Citizen* cit = new Citizen(ID, fn, ln, fc);
			// add this citizen to the list for the city
			this->addCitizen(cit);
			// delete the citizen outside of the city's list, as the addCitizen function created its own copy for the city itself
			delete cit;
		}
		// close the file
		file.close();
	}
}
// destructor for a city
City::~City()
{
	// create the file name in the same way as before, where the cityName is used, becasue it has to be specific to the city being called
	string filename = cityName + ".txt";
	// create an output file stream
	ofstream file;
	// open the file with the name created above
	file.open(filename);
	// check to see if the file opened properly, if not, say so and quit
	if (!file)
	{
		cout << "Could not store city, can't open file" << endl;
		return;
	}
	// print the population of the city to the top of the file
	file << "Population: " << population << endl;
	// for each citizen, print their id, name, and favorite color to the file on different lines
	for (int i = 0; i < population; i++)
	{
		// if this is the last citizen, do not cout the endl, as this will cause the eof() function to return false, thereby creating another citizen when retrieved
		if (i!=population-1)
		file << citizenList[i]->getID() << " " << citizenList[i]->getFirstName() << " " << citizenList[i]->getLastName() << " " << citizenList[i]->getFavoriteColor() << endl;
		else file << citizenList[i]->getID() << " " << citizenList[i]->getFirstName() << " " << citizenList[i]->getLastName() << " " << citizenList[i]->getFavoriteColor();

		// delete each citizen!!! we created copies using the new function for EACH citizen, so we must delete each citizen in the vector
		delete citizenList[i];
	}
	// close the file
	file.close();
}
// returns the city name
string City::getCityName()
{
	return cityName;
}
// returns the population of the city
int City::populationSize()
{
	return population;
}
// returns a pointer to the citizen at a specified index in the city's citizen list
Citizen* City::getCitizenAtIndex(int index)
{
	return citizenList[index];
}
// adds a citizen to the citizen list of a city
void City::addCitizen(Citizen* cit)
{
	// create a copy of the argument citizen with the new function and constructor using the pass-by-reference citizen
	Citizen* cit2 = new Citizen(cit);
	// push this citizen to the back of the citizenlist vector
	citizenList.push_back(cit2);
	// increment the population of the city
	population++;
}
// return a pointer to the citizen in the city with the specified id
Citizen* City::getCitizenWithID(int value)
{
	// evaluate each place in the vector until it runs out of citizens
	for (int i = 0; i < population; i++)
	{
		// use the getID function to return the id of the citizen at each index of the vector
		// if it is equal to the specified value, return that citizen
		if (citizenList[i]->getID() == value)
			return citizenList[i];
	}
	// if it is not found, say so and return null
	cout << "Could not find any citizen with this ID" << endl;
	return NULL;
}
// returns a vector containing each citizen whose favorite color is that specified in the argument
vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	// create a vector of pointers to citizens
	vector<Citizen*> vec;
	// go through the citizen list for the city, and each time a citizens favorite color matches the specified, push that citizen to the back of the new vector
	for (int i = 0; i < population; i++)
	{
		// check for equality using the getFavoriteColor function on the citizen at each index
		if (citizenList[i]->getFavoriteColor() == color)
			vec.push_back(citizenList[i]);
	}
	// return this list
	return vec;
}