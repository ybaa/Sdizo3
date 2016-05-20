#include "stdafx.h"
#include "KnapsackProblem.h"
using namespace std;


KnapsackProblem::KnapsackProblem() {
	//readDataFromFile("file.txt");
}


KnapsackProblem::~KnapsackProblem() {
}

void KnapsackProblem::generateFile(){
	srand(time(NULL));
	
	capacity = rand() % 10 + 10;// 50 + 50;
	numberOfItems = rand() % 6 + 4;

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
		for (int i = 0; i < numberOfItems*2 +1; i+=2) {
			file << vec[i] << " " << vec[i + 1] << "\n";
		}
		file.close();
	}

	vec.clear();
}


void KnapsackProblem::readDataFromFile() {
	
	fstream file("file.txt", ios::in);
	int help, help2;

	if (file.is_open()) {
		file >> capacity;
		file >> numberOfItems;

		if (file.fail())
			cout << "blad wczytywania pliku" << endl;

		for (int i = 0; i < numberOfItems; i++) {
			file >> help;
			row.push_back(help);
			file >> help;
			row.push_back(help);
			items.push_back(row);
			row.pop_back();
			row.pop_back();
			
		}
		row.clear();
	

		file.close();
	}
	else 
		cout << "blad wczytywania pliku" << endl;
	
}


void KnapsackProblem::bruteforce() {

}

void KnapsackProblem::solveDynamic() {

	row.clear();
	vector < vector <int> > result;
	for (int i = 0; i < numberOfItems + 1; i++) {
		result.push_back(vector<int>(capacity + 1, 0));
		}

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < capacity + 1; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i < numberOfItems+1; i++) {
		
		for (int j = 0; j < capacity+1; j++) {

			if (items[i-1][0] > j) {
				result[i][j] = result[i - 1][j];
			}
			else {
				if (result[i - 1][j] > result[i - 1][j - items[i - 1][0]] + items[i - 1][1])
					result[i][j] = result[i - 1][j];
				else
					result[i][j] = result[i - 1][j - items[i - 1][0]] + items[i - 1][1];
			}
		}
	}
	cout << "----------------------------------\n";

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < capacity + 1; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	
	vector < vector<int> > whichItems;
	//row.clear();


	int y = capacity;
	int x = numberOfItems;
	int help;
	int localCapacity = capacity;
	while (true) {
		if (x >= 1) {
			if (result[x][y] != result[x - 1][y]) {
				help = items[x - 1][0];
				row.push_back(items[x - 1][0]);
				row.push_back(items[x - 1][1]);
				whichItems.push_back(row);
				row.pop_back();
				row.pop_back();


				if (x == numberOfItems && y == capacity)
					break;

				x--;

				if (x == 0 && y == 0)
					break;

			}
			else {
				x--;
				while (result[x][y] == result[x - 1][y])
					x--;

				x--;
				help = items[x - 1][0];
				y -= help;

				row.push_back(items[x][0]);
				row.push_back(items[x][1]);
				whichItems.push_back(row);
				row.pop_back();
				row.pop_back();


			}



		}
		else
			break;
	}

	cout << endl;
	cout << "waga bydla to " << result[numberOfItems][capacity]<<endl;
	for (int i = 0; i < whichItems.size(); i++) {
		cout << whichItems[i][0] << " ";
		cout << whichItems[i][1];
		cout << endl;
	}


	
}

void KnapsackProblem::sort() {

	for (int i = 0; i < numberOfItems; i++) {
		for (int j = i; j < numberOfItems; j++) {
			if (items[i][0] > items[j][0]) {
				items[i].swap(items[j]);
			}
		}
	}
}

void KnapsackProblem::showContent() {
	int j = 0;
	for (int i = 0; i < numberOfItems; i++) {
		cout << items[i][j] << " ";
		j++;
		cout << items[i][j];
		j--;
		cout << endl;
	}
}
