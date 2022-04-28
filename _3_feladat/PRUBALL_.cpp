
/* https://www.spoj.com/problems/PRUBALL/ */

/* Az algoritmus magyarazata reszletesen a videoban!

Dinnyes Balazs Gazdasaginformatikus Bsc nappali hallgato ACM versenyfeladatok megoldasa kurzushoz, a 3. feladat

A feladat neve: PRUBALL

Adva van 2 teljesen ugyanolyan tipusu, ugyanolyan toresi tulajdonsagu uveg labda. Adva van egy tobb emeletes haz. Azt akarom
meghatározni hogy legrosszabb esetben hány emeleten kell kiprobalni leejteni egy labdat, hogy meghatarozzuk a legalacsonyabb 
emeletet ahonnan osszetorik. Minden emeletrol a probalkozas egy kiserletnek szamit. Ha ket vagy tobb labdank van akkor kevesebb
probalkozasra van szuksegunk persze. Ha pl az n. emeletrol ledobom az egyik labdat es az osszetorik, akkor nyilvan lefele fogok
 probalkozni, 
azaz alacsonyabb emelet is eleg lehet a vizsgalathoz, ezert a problemat visszavezetem egy kisebb emelet szamra, de egyel kevesebb labdara.
 Ha meg tegyuk fel a labda nem torne ossze, akkor nyilvan felfele probalkozom es egyel tobb emeletre vezetem vissza, de 
 ugyanannyi labdara. 

Megoldas: Ez egy tablazat kitoltos feladat, dinamikus programozas, amit egyszer mar kiszamoltunk, azt megegyszer nem teszuk
 igy idot, tarhelyet sporolva.
 
 Input adatok: 3 adat: elso a sorszam, aztan ugyanabban a sorban a labdak majd az emeletek szama.

Sample Input

4

1 2 10

2 2 100

3 2 300

4 25 900

Sample Output

1 4

2 14

3 24

4 10

*/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{	
	int szamlalo = 0, B, M, test, a[1001][51], torik, nemtorik, semmi;
	cin >> test;	
	while(++szamlalo != test + 1){
		cin >> semmi >> B >> M;
			a[0][1] = 0;
			a[1][1] = 0;
		// ha egy labdank van, a probalkozasok szama az emeletek szama
		for(int i = 1; i <= M; i++){
			a[i][1] = i - 1;
		}
		// ha tobb labdank van, de egy emeletunk akkor 1 mindig az eredmeny
		for(int i = 1; i<= B; i++){
			a[1][i] = 0;
			a[0][i] = 0;
		}
		if(B > 1 && M > 1)
		for(int i = 2; i <= B; i++){
			for(int j = 2 ; j <= M; j++){
					int min = 1000, minc;
				for(int k = j ; k >= 1; k--){
					// ha torik a labda akkor egyel kevesebb szintet és labdat nezek
					//  ha nem torik a labda akkor egyel magasabb szintet nezek ugyanannyi labdaval
					minc = (torik = a[k-1][i - 1] + 1) > (nemtorik = a[j - k][i] + 1) ? torik : nemtorik;
					if(min >= minc)
					min = minc;
				} 
				a[j][i] = min;
				min = 0; minc = 0;
			}
		}	
		// A fenti pontatlansagok korrigalasara +1 lesz a jó eredmeny
		cout << szamlalo << " " << a[M][B]+1 << endl;
	}
	return 0;
}
