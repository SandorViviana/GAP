#pragma once
#include <vector>
#include <random>
class Job
{
private:
	std::vector<int>cost;

	int getRandomNumber();

public:
	Job(int numberOfAgents);
	int getCostForJob(int i);
};

