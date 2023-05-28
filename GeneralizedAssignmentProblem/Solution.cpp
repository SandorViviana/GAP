#include "Solution.h"

int Solution::getPossibleAssignment(int i)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, i-1);
	return distr(eng);
}

int Solution::getResourcesNeededForAgent(std::vector<Agent> agents, int i) const
{
	int sum = 0;
	for (int j = 0; j < assignment.size(); j++)
	{
		if (assignment[j] == i)
		{
			sum += agents[i].resourceForJob(j);
		}

	}
	return sum;
}

Solution::Solution(int numberOfJobs, int numberOfAgents)
{
	assignment.resize(numberOfJobs);
	for (int i = 0; i < numberOfJobs; i++)
		assignment[i] = getPossibleAssignment(numberOfAgents);

}

Solution::Solution(std::vector<int> solution)
{
	assignment = solution;
}

Solution::Solution()
{
	assignment.resize(0);
}

int Solution::getFitness(std::vector<Job> jobs) const
{
	int fitness = 0;
	for (int i = 0; i < assignment.size(); i++)
	{
		fitness += jobs[i].getCostForJob(assignment[i]);
	}
	return fitness;
}

int Solution::getUnfitness(std::vector<Agent> agents) const
{
	int unfitness = 0;
	for (int i = 0; i < agents.size(); i++)
	{
		unfitness += std::max(0, getResourcesNeededForAgent(agents, i) - agents[i].getCapacity());
	}
	return unfitness;	
}

std::vector<int> Solution::getSolution()
{
	return assignment;
}

bool Solution::operator<(const Solution& s1) const
{
	return this->assignment < s1.assignment;
}
