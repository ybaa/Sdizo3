// Sdizo3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void localKnapsack() {
	KnapsackProblem knapsack;
	int choice = 0;
	string file;
	do {
		cout << "[1] wygeneruj losowe dane" << endl;
		cout << "[2] wczytaj dane z pliku" << endl;
		cout << "[3] algorytm dynamiczny" << endl;
		cout << "[4] wyjscie" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			knapsack.generateFile();
			knapsack.readDataFromFile("file.txt");
			knapsack.showContent();
			break;
		case 2:

			cout << "Podaj nazwe pliku: ";
			cin >> file;
			knapsack.readDataFromFile(file);
			knapsack.showContent();
			break;
		case 3:
			knapsack.sort();
			knapsack.solveDynamic();
			break;
		default:
			break;
		}
	} while (choice != 4);
}
void localSalesman() {
	TravellingSalesmanProblem salesman;
	int choice = 0;
	string file;
	do {
		cout << "[1] wygeneruj losowe dane" << endl;
		cout << "[2] wczytaj dane z pliku" << endl;
		cout << "[3] algorytm zachlanny" << endl;
		cout << "[4] wyjscie" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			salesman.generateFile();
			salesman.readFromFIle("file2.txt");
			salesman.showContent();
			break;
		case 2:

			cout << "Podaj nazwe pliku: ";
			cin >> file;
			salesman.readFromFIle(file);
			salesman.showContent();
			break;
		case 3:
			salesman.greedy();
			salesman.showVisitedTowns();
			break;
		default:
			break;
		}
	} while (choice != 4);
}

int main()
{
	
	int choice = 0;
	do {
		cout << "[1] Problem plecakowy" << endl;
		cout << "[2] Problem komiwojazera" << endl;
		cout << "[3] wyjscie" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			localKnapsack();
			break;
		case 2:
			localSalesman();
			break;
		case 3:
			break;

		default:
			break;
		}
	} while (choice != 3);
    return 0;
}

