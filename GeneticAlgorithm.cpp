#include "GeneticAlgorithm.h"



GeneticAlgorithm::GeneticAlgorithm(int populationSize) : 
	constants(), population(populationSize), 
	r_distribution(0, populationSize), d_distribution(0, 1.0)
{
	bestFitness = population.getFittestIndividual().getFitness();
}

GeneticAlgorithm::~GeneticAlgorithm()
{
}

int GeneticAlgorithm::getBestFitness() const
{
	return bestFitness;
}

GAIndividual GeneticAlgorithm::crossOver()
{
	GAIndividual newIndividual;
	int firstIndividual = r_distribution(r_engine);
	int secondIndividual = r_distribution(r_engine);
	for (int i = 0; i < constants.CHROMOSOME_LENGTH; i++)
		if (d_distribution(r_engine) <= constants.CROSSOVER_RATE)
			newIndividual.setGene(i, population.getIndividual(firstIndividual).getGene(i));
		else
			newIndividual.setGene(i, population.getIndividual(secondIndividual).getGene(i));
	return newIndividual;
}

GAIndividual GeneticAlgorithm::mutate(GAIndividual individual)
{
	for (int i = 0; i < constants.CHROMOSOME_LENGTH; i++)
		if (d_distribution(r_engine) <= constants.MUTATION_RATE)
			individual.setGene(i, r_distribution(r_engine));
	return individual;
}


void GeneticAlgorithm::evolvePopulation()
{
	GAPopulation newPopulation(population.getSize());
	for (int i = 0; i < population.getSize(); i++)
		newPopulation.saveIndividual(i, crossOver());
	for (int i = 0; i < population.getSize(); i++)
		newPopulation.saveIndividual(i, mutate(newPopulation.getIndividual(i)));
	population = newPopulation;
	int newBestFitness = population.getFittestIndividual().getFitness();
	if (newBestFitness > bestFitness)
		bestFitness = newBestFitness;
}
