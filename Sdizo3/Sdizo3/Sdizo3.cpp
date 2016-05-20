// Sdizo3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	/*KnapsackProblem knapsack;
	knapsack.generateFile();
	knapsack.readDataFromFile();
	knapsack.showContent();
	cout << "----------------------------------\n";
	knapsack.sort();
	knapsack.showContent();

	cout << "----------------------------------\n";
	knapsack.solveDynamic();*/


	TravellingSalesmanProblem salesman;
	salesman.generateFile();

	system("PAUSE");
    return 0;
}

