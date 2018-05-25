#pragma once

struct GAConstants
{
	const int SOLUTION_SEQUENCE[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	const double CROSSOVER_RATE = 0.5;
	const double MUTATION_RATE = 0.15;
	const int TOURNAMENT_SIZE = 5;
	const int CHROMOSOME_LENGTH = 10;
	const int MAX_FITNESS = 10;
};