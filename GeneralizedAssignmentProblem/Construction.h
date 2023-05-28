#pragma once
#include <vector>
#include <set>
#include <iostream>
#include "Solution.h"
class Construction
{
private:
	std::set<Solution>solutions;
	std::vector<Agent> agents;
	std::vector<Job> jobs;
	Solution bestSolution;

	int getRandomNumber(int i);
	bool isDuplicate(Solution s);
	

public:
	Solution mostUnfitMember();
	Solution mostFitMember();
	Construction(int numberOfJobs, int numberOfAgents);
	void constructSolutions(int N);
	Solution selectParent();
	Solution crossover(Solution parent1, Solution parent2);
	Solution mutation(Solution child);
	void replaceMember(Solution child);
	void improveSolution(int M);
	void writeSolution(Solution s);
	Solution getBestSolution();

};

