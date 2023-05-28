#pragma once
#include <vector>
#include <random>
class Agent
{
private:
	int capacity;
	std::vector<int> resource;

	int getRandomValues(int i);

public:
	Agent(int numberOfJobs);
	int getCapacity();
	int resourceForJob(int i);
};

