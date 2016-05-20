#include "stdafx.h"
#include "TravellingSalesmanProblem.h"


TravellingSalesmanProblem::TravellingSalesmanProblem() {
}


TravellingSalesmanProblem::~TravellingSalesmanProblem() {
}

void TravellingSalesmanProblem::generateFile() {
	srand(time(NULL));

	numberOfTowns = rand() % 10 + 1;
	
	vector <int> help;
	vector <vector < int> > vec;
	
	for (int i = 0; i < numberOfTowns; i++) {
		for (int j = i; j < numberOfTowns; j++) {
			vec.push_back(vector<int>(numberOfTowns, 0));
		}
	}

	for (int i = 0; i < numberOfTowns; i++) {
		for (int j = 0; j < i; j++) {
			vec[i][j] = rand() % 9 + 1;
			vec[j][i] = vec[i][j];
		}
	}

	


	fstream file("file2.txt", ios::out);
	if (file.good()) {
		file << numberOfTowns << "\n";
		for (int i = 0; i < numberOfTowns; i++) {
			file << i << " ";
			for (int j = 0; j < numberOfTowns; j++) {
				file << vec[i][j] << " ";
			}
			file << "\n";
		}
		file.close();
	}

	vec.clear();
}
