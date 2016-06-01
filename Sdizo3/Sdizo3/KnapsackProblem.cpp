#include "stdafx.h"
#include "KnapsackProblem.h"
using namespace std;


KnapsackProblem::KnapsackProblem() {
	//readDataFromFile("file.txt");
}


KnapsackProblem::~KnapsackProblem() {
	items.clear();
}

void KnapsackProblem::generateFile(){
	srand(time(NULL));
	
	//capacity = rand() % 20 + 10;
	//numberOfItems = rand() % 20 + 6;
	cout << "Podaj pojemnosc plecaka: ";
	cin >> capacity;
	cout << endl << "Podaj ilosc przedmiotow: ";
	cin >> numberOfItems;

	int size, value;

	vector <int> vec;

	vec.push_back(capacity);
	vec.push_back(numberOfItems);

	for (int i = 0; i < numberOfItems; i++) {
		size = rand() % 6 + 1;
		value = rand() % 6 + 1;
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


void KnapsackProblem::readDataFromFile(string data) {
	
	fstream file(data, ios::in);
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



void KnapsackProblem::solveDynamic() {

	row.clear();
	vector < vector <int> > result;
	for (int i = 0; i < numberOfItems + 1; i++) {
		result.push_back(vector<int>(capacity + 1, 0));
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
	cout << endl;

	//wyswietlanie macierzy po ktorej skacze algorytm 
/*
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < capacity + 1; j++) {
			cout<<setw(2) << result[i][j] << " ";
		}
		cout << endl;
	}*/

	// sprawdzenie ktore rzeczy zostaly wybrane
	
	vector < vector<int> > whichItems;
	

	int w = capacity;
	int i = numberOfItems;
	while (w>0 && i>0) {
		if (result[i][w] != result[i - 1][w]) {
			row.clear();
			row.push_back(items[i - 1][0]);
			row.push_back(items[i - 1][1]);
			whichItems.push_back(row);
			w -= items[i - 1][0];
			i--;
		}
		else
			i--;
	}

	// wypisanie wybranych przedmitow
	cout << endl;
	cout << "wartosc " << result[numberOfItems][capacity]<<endl;
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
