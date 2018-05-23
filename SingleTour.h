#pragma once
#include<memory>
#include<vector>
#include<algorithm>

#include"City.h"
#include"Repository.h"

class SingleTour
{
private:
	std::vector<std::shared_ptr<City>> cities;
	double distance;
public:
	SingleTour(Repository repo);
	~SingleTour();
	void setCity(int cityIndex, std::shared_ptr<City> city);
	std::shared_ptr<City> getCity(int cityIndex) const;
	std::vector<std::shared_ptr<City>> getTour() const;
	int getTourSize() const;
	void generateIndividual();
	double getDistance();
};