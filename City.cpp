#include "City.h"



City::City(int xCoord, int yCoord) : 
	xCoord(xCoord), yCoord(yCoord)
{
}


City::~City()
{
}

int City::getX() const
{
	return xCoord;
}

int City::getY() const
{
	return yCoord;
}

void City::setX(int x)
{
	this->xCoord = x;
}

void City::setY(int y)
{
	this->yCoord = y;
}

double City::distanceTo(std::shared_ptr<City> otherCity) const
{
	int xDist = std::abs(this->xCoord - otherCity->xCoord);
	int yDist = std::abs(this->yCoord - otherCity->yCoord);
	return std::sqrt(xDist * xDist + yDist * yDist);
}

std::ostream & operator<<(std::ostream & stream, const std::shared_ptr<City> city)
{
	stream << "city(" << city->getX() << ", " << city->getY() << ")";
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const City & city)
{
	stream << "city(" << city.xCoord << ", " << city.yCoord << ")";
	return stream;
}