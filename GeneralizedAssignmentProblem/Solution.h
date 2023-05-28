#pragma once
#include <vector>
#include <random>
#include "Agent.h"
#include "Job.h"
class Solution
{
private:
	std::vector<int>assignment;
	int getPossibleAssignment(int i);
	int getResourcesNeededForAgent(std::vector<Agent>agents, int i) const;
public:
	Solution(int numberOfJobs, int numberOfAgents);
	Solution(std::vector<int> solution);
	Solution();
	int getFitness(std::vector<Job>jobs) const;
	int getUnfitness(std::vector<Agent>agents) const;
	std::vector<int> getSolution();
	bool operator < (const Solution& s1) const;
};

