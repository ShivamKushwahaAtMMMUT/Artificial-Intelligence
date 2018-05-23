#include "SimulatedAnnealingTSP.h"



SimulatedAnnealingTSP::SimulatedAnnealingTSP(Repository &repo) : 
	tour(repo), random_distribution(0.0, 1.0)
{
}


SimulatedAnnealingTSP::~SimulatedAnnealingTSP()
{
}

double SimulatedAnnealingTSP::getBest() const
{
	return best;
}

double SimulatedAnnealingTSP::simulate()
{
	double temperature = 1000;
	double coolingRate = 0.003;
	double temp;
	best = tour.getDistance();
	while (temperature > 1)
	{
		temp = tour.getDistance();
		if (acceptanceProbability(best, temp, temperature) > random_distribution(random_generator))
			tour.generateIndividual();
		if (temp < best)
			best = temp;
		temperature *= 1 - coolingRate;
	}
	return best;
}

double SimulatedAnnealingTSP::acceptanceProbability(double energy, double newEnergy, double temperature)
{
	if (newEnergy < energy)
	{
		return 1.0;
	}
	return exp((energy - newEnergy) / temperature);
}