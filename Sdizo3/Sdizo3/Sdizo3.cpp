// Sdizo3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	//KnapsackProblem knapsack;
	////knapsack.generateFile();
	//knapsack.readDataFromFile("file.txt");
	//knapsack.showContent();
	//cout << "----------------------------------\n";
	//knapsack.sort();
	//knapsack.showContent();

	//cout << "----------------------------------\n";
	//knapsack.solveDynamic();


	TravellingSalesmanProblem salesman;
	salesman.generateFile();
	salesman.readFromFIle("file2.txt");
	salesman.showContent();
	int koszt = salesman.greedy();
	cout << endl << koszt << endl << endl;
	salesman.showVisitedTowns();
	system("PAUSE");
    return 0;
}

