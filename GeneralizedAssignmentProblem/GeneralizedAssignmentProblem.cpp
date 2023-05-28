// GeneralizedAssignmentProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Construction.h"

int main()
{
    
    int numberOfJobs, numberOfAgents;
    std::cout << "Introduceti numarul de joburi\n";
    std::cin >> numberOfJobs;
    std::cout << "Introduceti numarul de agenti\n";
    std::cin >> numberOfAgents;
    Construction c = Construction(numberOfJobs, numberOfAgents);
    int N, M;
    std::cout << "Introduceti numarul de solutii initiale de construit:";
    std::cin >> N;
    std::cout << "Introduceti numarul de iteratii:";
    std::cin >> M;
    c.constructSolutions(N);
    c.improveSolution(M);
    c.writeSolution(c.getBestSolution());
    c.writeSolution(c.mostUnfitMember());
    c.writeSolution(c.mostFitMember());

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
