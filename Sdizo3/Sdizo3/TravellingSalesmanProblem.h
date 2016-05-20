#pragma once
class TravellingSalesmanProblem {

	vector <vector <int> > distance;
	vector <int>  row;

	vector <int> listOfVisitedTowns;

	int numberOfTowns;

public:
	TravellingSalesmanProblem();
	~TravellingSalesmanProblem();

	void generateFile();
	void readFromFIle();
	void showContent();
	int greedy();
	void showVisitedTowns();
};

