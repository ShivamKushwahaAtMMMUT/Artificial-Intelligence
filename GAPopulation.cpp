#include "GAPopulation.h"

GAPopulation::GAPopulation(int populationSize) : individuals()
{
	for (int i = 0; i < populationSize; i++)
	{
		individuals.emplace_back();
	}
}

GAPopulation::~GAPopulation()
{
}

GAIndividual GAPopulation::getIndividual(int index)
{
	return individuals[index];
}

GAIndividual GAPopulation::getFittestIndividual()
{
	int fittest = 0;
	for (int i = 1; i < individuals.size(); i++)
		if (individuals[i].getFitness() >= individuals[fittest].getFitness())
			fittest = i;
	return individuals[fittest];
}

int GAPopulation::getSize()
{
	return static_cast<int>(individuals.size());
}

void GAPopulation::saveIndividual(int index, GAIndividual individual)
{
	individuals.insert(individuals.begin()+index, individual);
}
