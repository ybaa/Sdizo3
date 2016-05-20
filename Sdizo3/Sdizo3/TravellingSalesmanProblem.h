#pragma once
class TravellingSalesmanProblem {

	vector <vector <int> > distance;
	vector <vector <int> > row;

	int numberOfTowns;

public:
	TravellingSalesmanProblem();
	~TravellingSalesmanProblem();

	void generateFile();
};

