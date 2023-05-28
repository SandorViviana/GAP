#include "Job.h"

int Job::getRandomNumber()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 50);
	return distr(eng) + 1;
}

Job::Job(int numberOfAgents)
{
	cost.resize(numberOfAgents);
	for (int i = 0; i < numberOfAgents; i++)
		cost[i] = getRandomNumber();
}

int Job::getCostForJob(int i)
{
	return cost[i];
}
