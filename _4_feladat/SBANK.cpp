
/* https://www.spoj.com/problems/SBANK/ */

/* Az algoritmus magyarazata reszletesen a videoban!

Dinnyes Balazs Gazdasaginformatikus Bsc nappali hallgato ACM versenyfeladatok megoldasa kurzushoz, a 4. feladat

A feladat nev: SBANK

/* A feladatom: Az input file - ban megadott szamla szamokat kell novekvo sorendbe kiirnom. Amelyik tobbszor is elofordul, annak moge
irva az elofordulasi darabszamat.

Az problema kivalo lehetoseget nyujt a konyvtari map absztrakt adatszerkezet hasznalatara. Ez egy asszociativ kontiner, egy bejegyzese
egy kulcs - ertek part tartalmaz, es egy kulcsbol csak egyet tarol, es meg alapbol novekvo sorrendben is tarolja oket kulcs szerint.
Asszociativ azt jelenti, hogy egy sztring kulcsal indexelheto a kontiner.  */

/* Input:
2
6
03 10103538 2222 1233 6160 0142 
03 10103538 2222 1233 6160 0141 
30 10103538 2222 1233 6160 0141 
30 10103538 2222 1233 6160 0142 
30 10103538 2222 1233 6160 0141 
30 10103538 2222 1233 6160 0142 

5
30 10103538 2222 1233 6160 0144 
30 10103538 2222 1233 6160 0142 
30 10103538 2222 1233 6160 0145 
30 10103538 2222 1233 6160 0146 
30 10103538 2222 1233 6160 0143 

Output:
03 10103538 2222 1233 6160 0141 1
03 10103538 2222 1233 6160 0142 1
30 10103538 2222 1233 6160 0141 2
30 10103538 2222 1233 6160 0142 2

30 10103538 2222 1233 6160 0142 1
30 10103538 2222 1233 6160 0143 1
30 10103538 2222 1233 6160 0144 1
30 10103538 2222 1233 6160 0145 1
30 10103538 2222 1233 6160 0146 1
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
	int t, num, j,i;
	string kis, nagy, k1,k2,k3,k4, ossz;
	cin >> t;

	for(i = t; i>0; i-- ){
		cin >> num;
		map<string, int> maymap;
		for(j=0; j < num; j++){
		// beolvasom a köv szamla elemeit
		cin >> kis >> nagy >> k1 >> k2 >> k3 >> k4; 
		// sztringet kepzek a szamla elemeibeol
		ossz = kis +" " + nagy+" " + k1+ " " + k2 + " " + k3+ " " + k4 ;
		// a szamla sztringel pedig indexelem a map kontinert, egyel novelem mindig az elem szamot az 
		//  ujabb elofordulasakor.
		maymap[ossz]++;
		}
		// Iteratorral kiiratom a sort
		for (std::map<string,int>::iterator it=maymap.begin(); it!=maymap.end(); ++it)
    	cout << it->first << " " << it->second << '\n';
		cout << endl;
	}
	return 0;
}

