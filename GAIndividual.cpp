#include "GAIndividual.h"


GAIndividual::GAIndividual() :
	constants(), genes(constants.CHROMOSOME_LENGTH, 0),
	fitness(0), r_distribution(0, 9)
{
	generateIndividual();
}

GAIndividual::~GAIndividual()
{
}

void GAIndividual::generateIndividual()
{
	for (int i = 0; i < constants.CHROMOSOME_LENGTH; i++)
	{
		genes[i] = r_distribution(r_engine);
	}
	fitness = 0;
}

int GAIndividual::getFitness()
{
	if (fitness == 0)
		for (int i = 0; i < constants.CHROMOSOME_LENGTH; i++)
			if (genes[i] == constants.SOLUTION_SEQUENCE[i])
				fitness++;
	return fitness;
}

int GAIndividual::getGene(int index) const
{
	return genes[index];
}

void GAIndividual::setGene(int index, int value)
{
	genes[index] = value;
	fitness = 0;
}

