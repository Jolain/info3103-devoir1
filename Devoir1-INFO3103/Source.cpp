#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	char in[128]; // Sauve l'input pour vérification
	char out[128]; // Output vers la console de la valeure
	int decimalNum; // Contiens la valeur entrée (char -> int)
	unsigned long long unpck_bcd = 0; // Contient la valeure BCD
	unsigned long long result = 0; // Contient la valeure finale en binaire
	int decallage = 0; // Utilisé pour faire la conversion int -> bcd. Tiens compte du nombre de bytes a décaller par la gauche.
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
				memset(in, 0, sizeof(in)); // Clear l'array si des mauvaises données ont été entrées
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

	// 1 bytes (8-bit) par charactère, ie: 15 = [0000][0001] [0000][0010]
	while (decimalNum > 0) {
		unpck_bcd += (decimalNum % 10) << decallage;
		decimalNum = decimalNum / 10;
		decallage += 8; // Pousse le pointeur binaire vers le prochain byte (8 bit par la gauche)
	}
	// -----------------------------

	cout << "Nombre en BCD unpacked: " << unpck_bcd << endl;

	// ------------ 3 --------------
	// (bcd) -> (binaire)
	char temp = '0';
	// Assignage individuel des bytes
	int i = 0, j = 0;
	while (((i < sizeof(unpck_bcd)) || unpck_bcd > 0) && (temp != '\0')) {
		j = i * 4; // Correction pour loop
		temp = *(((char*) &unpck_bcd) + i); // Prend la valeur de chaque bytes de "unpck_bcd" et les mets dans un temp char

		// Fait la conversion de base 10 a base 2
		while ((int)temp > 0) {
			result += ((int)temp % 2) << j;
			temp = (int)temp / 2;
			j += 1; // Pousse le pointeur vers le prochain charactère [0-1]
		}
		unpck_bcd = unpck_bcd >> 4;
	}
	// -----------------------------

	cout << "Nombre en binaire: " << result << endl;

	// ----------- 4 ---------------
	// (binaire) -> (affichage)
	int k = 0;
	temp = '0';
	while (temp != '\0') {
		temp = *(((char*)&result) + k * 2); // Prend la valeur de chaque bytes de "result" et les mets dans un temp char
		out[k] = temp;
		k++;
	}
	
	cout << "La valeur entrée est: ";
	while (k != 0) {
		cout << out[k];
		k--;
	}
	cout << endl;

	system("PAUSE");
}