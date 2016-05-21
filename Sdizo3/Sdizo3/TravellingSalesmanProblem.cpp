#include "stdafx.h"
#include "TravellingSalesmanProblem.h"


TravellingSalesmanProblem::TravellingSalesmanProblem() {
}


TravellingSalesmanProblem::~TravellingSalesmanProblem() {
	distance.clear();
	listOfVisitedTowns.clear();
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
			// file << i << " ";
			for (int j = 0; j < numberOfTowns; j++) {
				file << vec[i][j] << " ";
			}
			file << "\n";
		}
		file.close();
	}

	vec.clear();
}

void TravellingSalesmanProblem::readFromFIle(string data) {
	fstream file(data, ios::in);
	int help, help2;

	if (file.is_open()) {
		file >> numberOfTowns;

		if (file.fail())
			cout << "blad wczytywania pliku" << endl;

		for (int i = 0; i < numberOfTowns; i++) {
			for (int j = 0; j < numberOfTowns; j++) {
				file >> help;
				row.push_back(help);
			}
			distance.push_back(row);
			row.clear();

		}

		file.close();
	}
	else
		cout << "blad wczytywania pliku" << endl;
}

void TravellingSalesmanProblem::showContent() {
	for (int i = 0; i < numberOfTowns; i++) {
		for (int j = 0; j < numberOfTowns; j++) {
			cout << distance[i][j] << " ";
		}
		cout << endl;
	}
}

int TravellingSalesmanProblem::greedy() {
	
	int cost = 0;
	int theLeastCost = 0;
	int currentTown;
	int help;
	int nextTown = 0;

	bool *visited = new bool[numberOfTowns];
	for (int i = 0; i < numberOfTowns; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < numberOfTowns ; i++) {
		theLeastCost += cost;
		cost = 2147483647;
		currentTown = nextTown;
		visited[currentTown] = true;
		listOfVisitedTowns.push_back(currentTown);
		for (int j = 0; j < numberOfTowns; j++) {
			if (distance[currentTown][j] < cost) {
				help = j;
				if (visited[help] == true)
					continue;
				else {
					cost = distance[currentTown][j];
					nextTown = help;
				}
			}
		}
	}
	
	delete[] visited;
	return theLeastCost;
}

void TravellingSalesmanProblem::showVisitedTowns() {
	for (int i = 0; i < listOfVisitedTowns.size(); i++) {
		cout << listOfVisitedTowns[i] << endl;
	}
}

