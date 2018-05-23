#include "Repository.h"



Repository::Repository() :
	cities()
{
}


Repository::~Repository()
{
}

void Repository::addCity(std::shared_ptr<City> city)
{
	cities.push_back(city);
}

std::shared_ptr<City> Repository::getCity(int index) const
{
	return cities[index];
}

int Repository::getNumberOfCities() const
{
	return static_cast<int>(cities.size());
}

std::vector<std::shared_ptr<City>> Repository::getCities() const
{
	return cities;
}
