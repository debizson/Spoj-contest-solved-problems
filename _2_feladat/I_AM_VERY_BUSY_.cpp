
/* https://www.spoj.com/problems/BUSYMAN/ */

/* Az algoritmus magyarazata reszletesen a videoban!

Dinnyes Balazs Gazdasaginformatikus Bsc nappali hallgato ACM versenyfeladatok megoldasa kurzushoz, a 2. feladat

A feladat az esemenykivalasztas problema klasszikus peldaja. Roviden tehat: adva vannak egy kozos eroforrast hasznalo, 
egymast idoben atfedo esemenyek. A cel meghatarozni egy olyan reszhalamzat ezen esemenyeknek, amely esemenyek egymassal kompatibilisek és 
maximalis elemszemu legyen ez a halmaz. Ket esemeny kompatibilis, ha v(i) <= s(j) vagy v(j) <= s(i), ahol a v fuggveny az idex - vel
jelolt esemeny veget jelzi, az s pedikg az kezdetet.

Megoldas: Novekvo sorrendbe teszem a az esemenyeket a befejezesuk szerint, majd ebben a sorozatban kersek kompatibilis
esemenyeket. Ezzel a moho algoritmussal garantaltan maximalis esemenyhalmazt kapok. */

/* A feladat nev: I am very busy */

#include <algorithm>
#include <iostream>
#include <map>
using namespace std; 
 
struct celebrate{
		int kezd, veg;
	};
 /* Az compa a konyvtari sort osszehasonlito fuggveny kirtekelo seged fuggvenye, tehat az esemenyek befejezesei szerit fogok
 rendezni. */
bool compa(celebrate i, celebrate j){
	return i.veg<j.veg;
	}	
	celebrate array[100000]; 
int main(){	
	int Test, N, m,res, n;	
	cin >> Test;	
	while(Test--){		
		cin >> N;
		for(int i = 0; i < N; i++){ 
			cin >> m >> n;					
			array[i].kezd = m;
			array[i].veg = n;			
		}
		// Itt vegzem a rendezest
		sort(array, array + N, compa);
		res = 0;
	    int	j  = -1;	
		// majd kialakitom a kompatibilis esemenyek szamat, ami az eredmeny lesz
		for( int i = 0; i < N; ++i){
			if(array[i].kezd >= j){
				j = array[i].veg;
				res++;
			}	
		}
		cout << res << endl;		
	}
	return 0;
}
 
