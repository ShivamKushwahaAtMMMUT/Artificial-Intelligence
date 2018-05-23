#pragma once
#include<memory>
#include<vector>
#include<random>
#include<cmath>

#include"City.h"
#include"Repository.h"
#include"SingleTour.h"

class SimulatedAnnealingTSP
{
private:
	double best;
	SingleTour tour;
	std::default_random_engine random_generator;
	std::uniform_real_distribution<double> random_distribution;
public:
	SimulatedAnnealingTSP(Repository &repo);
	~SimulatedAnnealingTSP();
	double getBest() const;
	double simulate();
	double acceptanceProbability(double energy, double newEnergy, double temperature);
};