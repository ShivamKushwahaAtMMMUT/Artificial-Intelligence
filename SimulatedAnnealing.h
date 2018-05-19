#pragma once
#include<random>
#include<cmath>

#include"Constants.h"

class SimulatedAnnealing
{
private:
	std::default_random_engine random_generator;
	std::uniform_real_distribution<double> random_distribution;
	double currentCoordX;
	double nextCoordX;
	double bestCoordX;
	SAConstants constants;
public:
	SimulatedAnnealing();
	~SimulatedAnnealing();
	double f(double x);
	double getEnergy(double x);
	double acceptanceProbability(double energy, double newEnergy, double temperature);
	double findOptimum();
};