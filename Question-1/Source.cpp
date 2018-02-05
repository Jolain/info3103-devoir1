#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {

	char in[128]; // Sauve l'input pour v�rification
	char out[128]; // Output vers la console de la valeure
	int decimalNum; // Contiens la valeur entr�e (char -> int)
	unsigned long long unpck_bcd = 0; // Contient la valeure BCD
	unsigned long long result = 0; // Contient la valeure finale en binaire
	int decallage = 0; // Utilis� pour faire la conversion int -> bcd. Tiens compte du nombre de bytes a d�caller par la gauche.
	bool loop = true; // Input validation

	cout << "Jolain Poirier - A00192864" << endl;
	cout << "INFO3103 - Devoir #1: Question #1" << endl << endl;
	cout << "Entrez un entier a convertir en BCD Unpacked: ";

	// ------------- 1 ---------------
	// Input validation
	while (loop) {
		cin >> in;
		for (auto c : in) {
			if (c == '\0') { break; }
			else if (!isdigit(c)) {
				cin.ignore(128, '\n');
				memset(in, 0, sizeof(in)); // Clear l'array si des mauvaises donn�es ont �t� entr�es
				cout << "Entree invalide. Entrez des nombres : ";
				loop = true;
				break;
			} else { loop = false; }
		}
	}
	// ------------------------------


	// -------------- 2 -------------
	// (char) -> (int)
	decimalNum = atoi(in);
	cout << "Nombre BCD inversé: ";
	// 1 bytes (8-bit) par charact�re, ie: 15 = [0000][0001] [0000][0010]
	while (decimalNum > 0) {
		unpck_bcd += (decimalNum % 10) << decallage;
		cout << decimalNum % 10 << "0";
		decimalNum = decimalNum / 10;
		decallage += 8; // Pousse le pointeur binaire vers le prochain byte (8 bit par la gauche)
	}
	cout << endl;
	// -----------------------------

	// ------------ 3 --------------
	// (bcd) -> (binaire)

	decallage = 0;
	cout << "Nombre binaire inversé: ";
	// Assignage individuel des bytes
	int i = 0, j = 0, temp;
	while (unpck_bcd > 0) {
		temp = atoi((char*)&unpck_bcd + i);
		for(j = 0; j < 4; j++) {
			result += (temp % 2) << decallage;
			cout << temp % 2;
			temp = temp / 2;
			decallage += 1; // Procède bit par bit
		}
		unpck_bcd = unpck_bcd << 4; // Après processing du byte, process le prochain
	}
	// -----------------------------

	// ----------- 4 ---------------
	// (binaire) -> (affichage)
	int k = 0;
	temp = *((char*)&result);
	while (result != 0) {
		for (int n = 0; n < 4; n++) {
			temp = *((char*)&result + n);
			if (temp != '\0') { out[k + n % 4] = *((char*)&result + n) * pow(2, n); } // Fait la conversion de binaire a decimal
		}
		result = result >> 8;
		k += 4;
	}
	
	cout << "La valeur entree est: " << out;
	cout << endl;

	system("PAUSE");
	// -----------------------------
}