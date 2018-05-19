#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing() :
	random_distribution(0.0, 1.0)
{
}

SimulatedAnnealing::~SimulatedAnnealing()
{
}

double SimulatedAnnealing::f(double x)
{
	return (x - 0.3)*(x - 0.3)*(x - 0.3) - 5 * x + x * x - 2;
}

double SimulatedAnnealing::getEnergy(double x)
{
	return f(x);
}

double SimulatedAnnealing::acceptanceProbability(double energy, double newEnergy, double temperature)
{
	if (newEnergy < energy)
	{
		return 1.0;
	}
	return exp((energy - newEnergy) / temperature);
}

double SimulatedAnnealing::findOptimum()
{
	double temperature = constants.MAX_TEMPERATURE;
	currentCoordX = constants.MIN_COORDINATEX;
	bestCoordX = constants.MIN_COORDINATEX;
	while (temperature > constants.MIN_TEMPERATURE)
	{
		nextCoordX = random_distribution(random_generator) * (constants.MAX_COORDINATEX - constants.MIN_COORDINATEX);
		double energry = getEnergy(currentCoordX);
		double newEnergry = getEnergy(nextCoordX);
		if (acceptanceProbability(energry, newEnergry, temperature) > random_distribution(random_generator))
		{
			currentCoordX = nextCoordX;
		}
		if (f(currentCoordX) < f(bestCoordX))
		{
			bestCoordX = currentCoordX;
		}
		temperature *= 1 - constants.COOLING_RATE;
	}
	return bestCoordX;
}