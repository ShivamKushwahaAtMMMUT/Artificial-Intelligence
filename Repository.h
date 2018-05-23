#pragma once
#include<memory>
#include<vector>
#include<array>

#include"City.h"

class Repository
{
private:
	std::vector<std::shared_ptr<City>> cities;
public:
	Repository();
	~Repository();
	void addCity(std::shared_ptr<City> city);
	std::shared_ptr<City> getCity(int index) const;
	int getNumberOfCities() const;
	std::vector<std::shared_ptr<City>> getCities() const;
};