#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	char input[128]; // Holds the input for processing
	char unpck_bcd[256]; // Array representing our input in BCD format
	unsigned long long result; // Contient la valeure finale en binaire
	bool loop = true; // Used for input validation
	int counter;

	cout << "Jolain Poirier - A00192864" << endl;
	cout << "INFO3103 - Devoir #1: Question #1" << endl << endl;
	cout << "Entrez un entier a convertir en BCD Unpacked: ";

	// Input validation
	while (loop) {
		cin >> input;
		for (auto c : input) {
			if (!isdigit(c)) {
				cin.ignore(256, '\n');
				memset(input, 0, sizeof(input)); // Reset the char array
				cout << "Entree invalide. Entrez des nombres : ";
				loop = true;
				break;
			} else { loop = false; }
		}
	}

	// Transform the input into a BCD unpacked format
	counter = 0;
	for (auto c : input) {
		unpck_bcd[counter] = '0';
		unpck_bcd[counter + 1] = c;
		counter = counter + 2;
	}



}