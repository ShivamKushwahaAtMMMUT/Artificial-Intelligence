#pragma once
#include<vector>
#include<memory>
#include"GAIndividual.h"
class GAPopulation
{
private:
	std::vector<GAIndividual> individuals;
public:
	GAPopulation(int populationSize);
	~GAPopulation();
	GAIndividual getIndividual(int index);
	GAIndividual getFittestIndividual();
	int getSize();
	void saveIndividual(int index, GAIndividual individual);
};