#include "Construction.h"

int Construction::getRandomNumber(int i)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, i-1);
	return distr(eng);
}

bool Construction::isDuplicate(Solution s)
{
	std::set<Solution> temp = solutions;
	temp.insert(s);
	if (temp.size() == solutions.size())
		return true;
	return false;
}

Solution Construction::mostUnfitMember()
{
	Solution s;
	int unfitness = 0;
	for (std::set<Solution>::iterator it = solutions.cbegin(); it != solutions.cend(); it++)
	{
		if (it->getUnfitness(agents) > unfitness)
		{
			unfitness = it->getUnfitness(agents);
			s = *it;
		}
	}
	return s;
}

Solution Construction::mostFitMember()
{
	Solution s;
	int fitness = 0;
	for (std::set<Solution>::iterator it = solutions.cbegin(); it != solutions.cend(); it++)
	{
		if (it->getFitness(jobs) > fitness)
		{
			fitness = it->getFitness(jobs);
			s = *it;
		}
	}
	return s;
}

Construction::Construction(int numberOfJobs, int numberOfAgents)
{
	for (int i = 0; i < numberOfAgents; i++)
		agents.push_back(Agent(numberOfJobs));
	for (int i = 0; i < numberOfJobs; i++)
		jobs.push_back(Job(numberOfAgents));
	
}

void Construction::constructSolutions(int N)
{
	while(solutions.size()<N)
		solutions.insert(Solution(jobs.size(), agents.size()));
}

Solution Construction::selectParent()
{

	Solution v1 = *next(solutions.begin(), getRandomNumber(solutions.size()));
	Solution v2 = *next(solutions.begin(), getRandomNumber(solutions.size()));
	if (v1.getFitness(jobs) < v2.getFitness(jobs))
		return v1;
	else return v2;

}

Solution Construction::crossover(Solution parent1, Solution parent2)
{
	int p = getRandomNumber(jobs.size());
	int i = getRandomNumber(2);
	std::vector<int> solution1 = parent1.getSolution();
	std::vector<int> solution2 = parent2.getSolution();
	std::vector<int> assignment;
	if (i == 0)
	{
		for (int i = 0; i < p; i++)
			assignment.push_back(solution1[i]);
		for (int j = p; j < solution2.size(); j++)
			assignment.push_back(solution2[j]);
	}
	else
	{
		for (int i = 0; i < p; i++)
			assignment.push_back(solution2[i]);
		for (int j = p; j < solution2.size(); j++)
			assignment.push_back(solution1[j]);
	}
	return Solution(assignment);
}

Solution Construction::mutation(Solution child)
{
	int g1 = getRandomNumber(jobs.size());
	int g2 = getRandomNumber(jobs.size());
	std::vector<int> newSolution = child.getSolution();
	int aux = newSolution[g1];
	newSolution[g1] = newSolution[g2];
	newSolution[g2] = aux;
	return Solution(newSolution);	
}

void Construction::replaceMember(Solution child)
{
	
		Solution s = mostUnfitMember();
		if (s.getSolution().size() != 0)
		{
			solutions.erase(s);
		}
		else solutions.erase(mostFitMember());
		solutions.insert(child);
	
}

void Construction::improveSolution(int M)
{
	int i = 0;
	while (i < M)
	{
		Solution p1 = selectParent();
		Solution p2 = selectParent();
		Solution child = mutation(crossover(p1, p2));
		if (!isDuplicate(child))
		{
			replaceMember(child);
			Solution t = Solution(bestSolution);
			Solution aux = getBestSolution();
			if (aux.getFitness(jobs) < bestSolution.getFitness(jobs))
			{
				
				bestSolution = aux;
				
			}
			i++;
			
		}
	}
}

void Construction::writeSolution(Solution s)
{
	for (int i = 0; i < jobs.size(); i++)
		std::cout << i << " ";
	std::cout<<std::endl;
	std::vector<int> solution = s.getSolution();
	for (int i = 0; i < jobs.size(); i++)
		std::cout << solution[i] << " ";
	std::cout << std::endl;
	std::cout << "Cost: " << s.getFitness(jobs) << "; Unfitness: " << s.getUnfitness(agents) << std::endl;
}

Solution Construction::getBestSolution()
{
	Solution s= *solutions.cbegin();
	int fitness = solutions.cbegin()->getFitness(jobs);
	for (std::set<Solution>::iterator it = solutions.cbegin()++; it != solutions.cend(); it++)
	{
		if (it->getFitness(jobs) < fitness)
		{
			fitness = it->getFitness(jobs);
			s = *it;
		}
	}
	//if (bestSolution.getSolution().size() == 0 || s.getFitness(jobs) < bestSolution.getFitness(jobs))
		//bestSolution = Solution(s);
	//return bestSolution;
	return s;
}
