#pragma once
#include<vector>
#include<memory>
#include<random>
#include"GAConstants.h"

class GAIndividual
{
private:
	GAConstants constants;
	std::vector<int> genes;
	int fitness;
	std::default_random_engine r_engine;
	std::uniform_int_distribution<int> r_distribution;
public:
	GAIndividual();
	~GAIndividual();
	void generateIndividual();
	int getFitness();
	int getGene(int index) const;
	void setGene(int index, int value);
};