#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<memory>

class City
{
private:
	int xCoord;
	int yCoord;
public:
	City(int x, int y);
	~City();
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	double distanceTo(std::shared_ptr<City> otherCity) const;
	friend std::ostream& operator<<(std::ostream& stream, const std::shared_ptr<City> city);
	friend std::ostream & operator<<(std::ostream & stream, const City & city);
};