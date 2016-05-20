#pragma once
using namespace std;
class KnapsackProblem {

	int capacity;
	int numberOfItems;

	vector < vector <int> > items;
	vector < int > row;
	vector < vector <int> > sortedItems;

public:
	KnapsackProblem();
	~KnapsackProblem();

	void generateFile();
	void readDataFromFile();
	void solveDynamic();
	void bruteforce();
	void showContent();
	void sort();
	
};

