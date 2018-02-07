#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {

	int base; // La base numérique avec laquelle on travaille
	char maxChar = 0; // Représente la valeure max de la base alpha-numériquement
	char input[32]; // Stocke l'input pour verification et manipulation
	char table[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	unsigned long long value = 0; // Utilise pour faire les calculs de conversion
	unsigned long long result = 0; // Contient la valeure finale dans la base voulue
	int decallage = 0; // Utilis� pour faire la conversion int -> bcd. Tiens compte du nombre de bytes a d�caller par la gauche.
	bool loop = true; // Input validation

	cout << "Jolain Poirier - A00192864" << endl;
	cout << "INFO3103 - Devoir #1: Question #5" << endl << endl;
	cout << "Entrez la base numérique voulue [2-16]: ";

	// ------------- 1 ---------------
	// Input validation pour la base
	while (loop) {
		cin >> input;
		for (auto c : input) {
			if (c == '\0') { break; }
			else if (!isdigit(c) || atoi(input) > 16 || atoi(input) < 2) {
				cin.ignore(128, '\n');
				memset(input, '\0', sizeof(input)); // Clear l'array si des mauvaises donn�es ont �t� entr�es
				cout << "Entree invalide. Entrez une valeur entre 2 et 16: ";
				loop = true;
				break;
			}
			else { loop = false; }
		}
	}

	base = atoi(input);
	maxChar = table[base - 1];

	cout << "Entrez la valeur decimale a convertir en base " << base << ": ";

	// Input validation pour le nombre
	memset(input, '\0', sizeof(input)); // Clear l'array avant l'entrée de nouvelles données
	loop = true;
	while (loop) {
		cin >> input;
		for (auto c : input) {
			if (c == '\0') { break; }
			else if (!isdigit(c)) {
				cin.ignore(128, '\n');
				memset(input, '\0', sizeof(input)); // Clear l'array si des mauvaises donn�es ont �t� entr�es
				cout << "Entree invalide. Essayez a nouveau: ";
				loop = true;
				break;
			}
			else { loop = false; }
		}
	}

	value = atoi(input);
	// ------------------------------


	// -------------- 2 -------------
	// (convertion)
	while (value > 0) {
		result += (value % base) << decallage;
		value = value / base;
		decallage += 4;
	}
	// -----------------------------


	// ----------- 3 ---------------
	// (affichage)

	char output[32];
	memset(output, '\0', sizeof(output));
	int i = 0;
	int temp;
	// Parcours le long long à partir du least significant bit, 4 bits a la fois
	while (result > 0) {
		temp = result & 0b1111;
		output[i] = table[temp];
		i++;
		result = result >> 4;
	}
	i--; // Correction du pointeur pour retourner sur le bon charactère

	cout << "La valeur entree est: ";
	while (i >= 0) {
		if (!isalpha(output[i])) {
			cout << output[i]; 
		}
		else {
			cout << output[i];
		}
		i--;
	}
	cout << endl;

	system("PAUSE");
	// -----------------------------
}