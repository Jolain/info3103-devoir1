#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {

	int base; // La base numérique avec laquelle on travaille
	char maxChar = 0; // Représente la valeure max de la base alpha-numériquement
	char input[32]; // Stocke l'input pour verification et manipulation
	unsigned long long unpck_bcd = 0; // Contient la valeure BCD
	unsigned long long result = 0; // Contient la valeure finale en binaire
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

	// Déterminer la valeur maximale
	if (base <= 10) {
		maxChar = base;
	}
	else {
		switch (base) {
		case 11:
			maxChar = 'A';
			break;
		case 12:
			maxChar = 'B';
			break;
		case 13:
			maxChar = 'C';
			break;
		case 14:
			maxChar = 'D';
			break;
		case 15:
			maxChar = 'E';
			break;
		case 16:
			maxChar = 'F';
			break;
		}
	}

	cout << "Entrez la valeur a convertir en base " << base << ": ";

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
	// ------------------------------


	// -------------- 2 -------------
	// (convertion)




	// -----------------------------

	// ----------- 3 ---------------
	// (affichage)

	// Comme l'information a été stocké dans un format BCD et puis converti en "binaire", les données
	// a ce point ci ont subi les transformations suivantes:
	// (chaque bracket représente 8-bits sur la mémoire

	//					 BCD           Codé binaire
	// ie: (int) 57 -> [05][07] -> [00000101][00000111]

	bit = 0;
	bool found = false;
	char output[32];
	memset(output, '\0', sizeof(output));
	int i = 0;

	// Parcours le long long à partir du least significant bit, 4 bits a la fois
	while (result > 0) {
		temp = result & 0b1111;
		if (base <= 10 || temp < 10) {
			output[i] = (char)temp;
		}
		else {
			char c = '0';
			switch (temp) {
			case 10:
				c = 'A';
				break;
			case 11:
				c = 'B';
				break;
			case 12:
				c = 'C';
				break;
			case 13:
				c = 'D';
				break;
			case 14:
				c = 'E';
				break;
			case 15:
				c = 'F';
				break;
			}
			output[i] = c;
		}
		i++;
		result = result >> 8; // Saute les [0000] du BCD
	}
	i--; // Correction du pointeur pour retourner sur le bon charactère

	cout << "La valeur entree est: ";
	while (i >= 0) {
		if (!isalpha(output[i])) {
			cout << (char)('0' + output[i]);  // Force la conversion en char de output[i]
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