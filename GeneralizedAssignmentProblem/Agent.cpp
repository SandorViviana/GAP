#include "Agent.h"

int Agent::getRandomValues(int i)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, i);
	return distr(eng) + 1;
}

Agent::Agent(int numberOfJobs)
{
	this->capacity = getRandomValues(1000);
	this->resource.resize(numberOfJobs);
	for (int i = 0; i < numberOfJobs; i++)
		resource[i] = getRandomValues(50);
}

int Agent::getCapacity()
{
	return capacity;
}

int Agent::resourceForJob(int i)
{
	return resource[i];
}
