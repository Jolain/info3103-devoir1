#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {

	char in[32]; // Sauve l'input pour v�rification
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
			}
			else { loop = false; }
		}
	}
	// ------------------------------


	// -------------- 2 -------------
	// (char) -> (bcd)
	decimalNum = atoi(in);
	// 1 bytes (8-bit) par charact�re, ie: 15 = [0000][0001] [0000][0010]
	while (decimalNum > 0) {
		unpck_bcd += (decimalNum % 10) << decallage;
		decimalNum = decimalNum / 10;
		decallage += 8; // Pousse le pointeur binaire vers le prochain byte (8 bit par la gauche)
	}
	// -----------------------------

	// ------------ 3 --------------
	// (bcd) -> (binaire)

	decallage = 0;
	// Conversion de chaque caractère en bit
	// *** Lors de la conversion en BCD, les nombres sont déjà codés en binaires dans la mémoire
	// donc il n'est pas nécessaire de coder en binaire en plus. Sinon, avec mon format, l'algorithme
	// ne fonctionne seulement qu'avec des nombres a un charactère. Cette partie copie et supprime
	// bit par bit la valeure BCD pour simuler la conversion en binaire.

	int bit = 0, temp;
	while (unpck_bcd > 0) {
		temp = unpck_bcd & 1; // Retourne la valeur du bit (1 ou 0)
		result += temp << bit;
		unpck_bcd = unpck_bcd >> 1; // Shift la valeur de unpck_bcd de 1 bit pour parcourir au complet
		bit++;
	}
	// -----------------------------

	// ----------- 4 ---------------
	// (binaire) -> (affichage)

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
		output[i] = temp;
		i++;
		result = result >> 8; // Saute les [0000] du BCD
	}
	i--; // Correction du pointeur pour retourner sur le bon charactère

	cout << "La valeur entree est: ";
	while (i >= 0) {
		cout << (int)output[i];
		i--;
	}
	cout << endl;

	system("PAUSE");
	// -----------------------------
}