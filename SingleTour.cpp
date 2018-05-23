#include "SingleTour.h"



SingleTour::SingleTour(Repository repo) : 
	cities(repo.getCities()), distance(0)
{
}

SingleTour::~SingleTour()
{
}

void SingleTour::setCity(int cityIndex, std::shared_ptr<City> city)
{
	cities[cityIndex] = city;
	distance = 0;
}

std::shared_ptr<City> SingleTour::getCity(int cityIndex) const
{
	return cities[cityIndex];
}

std::vector<std::shared_ptr<City>> SingleTour::getTour() const
{
	return cities;
}

int SingleTour::getTourSize() const
{
	return static_cast<int>(cities.size());
}

void SingleTour::generateIndividual()
{
	std::random_shuffle(cities.begin(), cities.end());
	distance = 0;
}

double SingleTour::getDistance()
{
	if (distance == 0)
	{
		for (int cityIndex = 0; cityIndex < getTourSize(); cityIndex++)
		{
			std::shared_ptr<City> fromCity = getCity(cityIndex);
			std::shared_ptr<City> destCity;
			if (cityIndex + 1 < getTourSize())
				destCity = getCity(cityIndex + 1);
			else
				destCity = getCity(0);
			distance += fromCity->distanceTo(destCity);
		}
	}
	return distance;
}
