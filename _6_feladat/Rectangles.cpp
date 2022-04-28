
/* https://www.spoj.com/problems/AE00/
 
 Az algoritmus magyarazata reszletesen a videoban!

Dinnyes Balazs Gazdasaginformatikus Bsc nappali hallgato ACM versenyfeladatok megoldasa kurzushoz, a 6. feladat

A feladat nev: Rectangles

A feladatom, hogy N darab egysegnegyzetbol kirakjak annyi fele teglalapot ahanyat tudok, az egymassal izomorfokat egynek vegyuk.

Melgoldas: a ket dimenziohoz ket for ciklust futtatok. Ezt a ket ciklus tagot szorzom mindig egymassal, azaz i*j, es ha ez a szorzat
kisebb vagy egyenlo mint n akkor van egy uj teglalap. A masodik ciklust az elso ciklus aktualis ertekevel inicializalom mindig, igy 
zarom ki az izomof esetek dupla szamitasat: mert a * b az ugyanaz mint b * a. 

pelda input:

6

pelda output:

8

*/

#include <iostream>
using namespace std;

int main() {
	// a teglalapok szama
	long long int ossz = 0;
	int N;
	// beolvasom az egysegnegyzetek szamat
	cin >> N;
	// Fent irtam az erdekes ciklusszervezesrol
	for(int i = 1; i <= N; i++){
		for(int j = i; j<= N; j++){
			if(i * j <= N)
			ossz += 1;
		}
	}
	// kiiratom az eredmenyt
	cout << ossz << endl; 

	return 0;
}
