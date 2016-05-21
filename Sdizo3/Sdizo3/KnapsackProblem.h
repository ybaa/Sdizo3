#pragma once
using namespace std;
class KnapsackProblem {

	int capacity;
	int numberOfItems;

	vector < vector <int> > items;
	vector < int > row;

public:
	KnapsackProblem();
	~KnapsackProblem();

	void generateFile();
	void readDataFromFile(string);
	void solveDynamic();
	void bruteforce();
	void showContent();
	void sort();
	
};

