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

	decallage = 0;
	// Assignage individuel des bytes
	while (unpck_bcd > 0) {
		result += (unpck_bcd % 2) << decallage;
		unpck_bcd = unpck_bcd / 2;
		decallage += 4; // Prend 4-bit par charactere 1 ou 0
	}
	// -----------------------------

	cout << "Nombre en binaire: " << result << endl;

	// ----------- 4 ---------------
	// (binaire) -> (affichage)
	int k = 0;
	auto temp = *((char*)&result);
	while (result != 0) {
		for (int n = 0; n < 4; n++) {
			temp = *((char*)&result + n);
			if (temp != '\0') { out[k + n % 4] = *((char*)&result + n) * pow(2, n); } // Fait la conversion de binaire a decimal
		}
		result = result >> 8;
		k += 4;
	}
	
	cout << "La valeur entrée est: " << out;
	cout << endl;

	system("PAUSE");
}