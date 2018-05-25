#pragma once
#include<random>
#include"GAPopulation.h"
#include"GAIndividual.h"
#include"GAConstants.h"

class GeneticAlgorithm
{
private:
	std::default_random_engine r_engine;
	std::uniform_int_distribution<int> r_distribution;
	std::uniform_real_distribution<double> d_distribution;
	GAPopulation population;
	GAConstants constants;
	int bestFitness;
private:
	GAIndividual crossOver();
	GAIndividual mutate(GAIndividual individual);
public:
	GeneticAlgorithm(int populationSize);
	~GeneticAlgorithm();
	int getBestFitness() const;
	void evolvePopulation();
};