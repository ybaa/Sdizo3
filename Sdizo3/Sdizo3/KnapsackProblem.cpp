#include "stdafx.h"
#include "KnapsackProblem.h"



KnapsackProblem::KnapsackProblem() {
}


KnapsackProblem::~KnapsackProblem() {
}

void KnapsackProblem::generateFile() {
	srand(time(NULL));
	
	capacity = rand() % 50 + 50;
	numberOfItems = rand() % 36 + 15;

	int size, value;

	vector <int> vec;

	vec.push_back(capacity);
	vec.push_back(numberOfItems);

	for (int i = 0; i < numberOfItems; i++) {
		size = rand() % 16 + 1;
		value = rand() % 16 + 1;
		vec.push_back(size);
		vec.push_back(value);
	}

	fstream file("file.txt", ios::out);
	if (file.good()) {
		for (int i = 0; i < numberOfItems; i+=2) {
			file << vec[i] << " " << vec[i + 1] << "\n";
		}
		file.close();
	}
}
