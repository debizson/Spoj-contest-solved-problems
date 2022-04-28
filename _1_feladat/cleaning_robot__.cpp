
/* https://www.spoj.com/problems/CLEANRBT/ */

 
/* Az algoritmus magyarazata reszletesen a videoban!

Dinnyes Balazs Gazdasaginformatikus Bsc nappali hallgato ACM versenyfeladatok megoldasa kurzushoz, az 1. feladat

A feladat nev: Cleaning Robot

A feladatom, egy Robot porszivo mukodeset leiro algritmus megirasa. 
Adva van egy maximum 20X20 - as matrix, mely a tisztitando szobat reprezentalja. Minden pozicioban 4 fele eleme lehet
a szobanak. Ezek

'.' : egy tiszta pontja a szobanak;
'*' : egy piszkos pontja a szobanak;
'x' : egy butor, azaz akadaly pont, a porszivo itt nem tud athaladni;
'o' : a kezdopontja a porszivonak;


Tehat az inputunk egy ilyen jelekbol allo terkep, amit sorfolytonosan olvasunk be.
Az algoritmust a piszkos foltok kordinatainak a tudataban kell megirnunk, es az a cel, hogy minel kevesebbet 
mozogjon a porszivo.


Inputra példák:
(a két szám az alatta levo matrix merete)

7 5
.......
.o...*.
.......
.*...*.
.......
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
10 10
..........
..o.......
..........
..........
..........
.....xxxxx
.....x....
.....x.*..
.....x....
.....x....
0 0

Out putjai:

8
49
-1

Lathato, hogy a harmadik esetben egy piszkos folt van elzarva butorral. Ebben az estben a kimenet mindig a -1 - es szam.

Tekintheto a matrix elemei mint a szoba graf pontjai.
Ahogy emlitettem a feladat az, hogy a porszivo a kiindulasi helyetol, a legrovidebb korutat megteve, erintve a 
piszkos foltokat, visszaterjen a kiindulai helyzetbe. Meg kell adni tehat egy minimalis Hamilton - kort a szobat reprezentalo
grafban, ugy, hogy a kor pontjainak a piszkos pontokat kell venni. 

Megoldas: 1. lepes: Minden 2 piszkos pont között meghatarozom a legrovidebb korutat. Ezt minden piszkos pontbol indulo szelessegi keresessel teszem meg. Igy vegul feltudom allitani a teljes grafot.
	2. lepes: Ebben a grafban keresek egy Hamilton kort, a pontok sorrendjevel vett permutacioit vizsgalva. */

    #include <iostream>
    #include <algorithm>
    #include <list>
    using namespace std;
       
    // w: a szoba szelessege, h: a szoba magassaga, reachnum: szamolja, hogy minden piszkos folt megvan - e
    int w,h,u, reach_num;         
    // apa: a szobagraf apa fuggvenye // a szobagraf tavolsag fuggvenye
    int apa[401], tav[401];
    // dirty_ps: max 10 darab piszkos folt van,  dpnum: a piszkos foltok szama
    int dirty_ps[11], dpnum, dp_tav[11][11];  // az egyes piszkos foltok kozti legrovidebb tavolsag
    // a szoba 
    char array[401];
    list<int> sor;
     
    void Kiel_ubol_(int s,int v, char jel){
    	//ha a pozicio pl kimegy a szobabol akkor azt a pontot ignoraljuk
    	if(v <= 0 || v > w * h )
    		return;
    	if(jel == '+')
    		if(v % w == 1)
    			return;
    	if(jel == '-')
    		if(v % w == 0)
    			return;
    	if(array[v] == 'x')
    		return;
    	if(apa[v] < 0){
    		apa[v] = u;
    		tav[v] = tav[u] + 1;
    		sor.push_back(v);
    		for(int i = 1; i <= dpnum; i++){
    			if(v == dirty_ps[i]){
    			dp_tav[s][i] = tav[v];
    			dp_tav[i][s] = tav[v];
    			reach_num++;
    			}
    		} 
    	}		
    }         
    bool Szeltkeres(int s, int kezdocsucs){
    	for(int i = 1; i<=400; i++){
    		apa[i] = -1;
    		tav[i] = 2000000000;
    	}	
    	tav[kezdocsucs] = 0;
    	apa[kezdocsucs] = 0;
    	sor.push_back(kezdocsucs);
    	while(sor.size() > 0){
    		u = sor.front();
    		sor.pop_front();
    		Kiel_ubol_(s,u+1,'+');
    		Kiel_ubol_(s,u+w,'0');
    		Kiel_ubol_(s,u-1,'-');
    		Kiel_ubol_(s,u-w,'0');		
    	}	
    	return(reach_num == dpnum);	
    }
    // a main fuggveny
    int main() {
    	//t: a szoba aktualis beolvasando karaktere; wo, ho: a porszivo kezdopontjanak koordinatai
    	char t, wo, ho;
    	//beolvasom a szoba mereteit	
    	cin >> w >> h;
    	// amig az input mertetek nem 0 - k
    	while( w != 0 || h != 0){
    		dpnum = 0;
    		reach_num = 0;
    		// a beolvaso ciklusok
    		for(int i = 1; i <= h; i++ ){
    			for(int j = 1; j <= w; j++){	
    				//beolvassuk a kov. karaktert
    				cin >> t;
    				//ha a kov. karakter a porszivo kezdopontja, akkor lementem a koordinatait
    				if(t == 'o'){
    					ho = i;
    					wo = j;	
    				}
    				//ha a kov. karakter egy piszkos folt, akkor elmentem a poziciojat egy linearis modon,  ez egyetlen
    				// szam, igy konnyebb dolgozni vele :)
    				if(t == '*')
    					dirty_ps[++dpnum] = (i - 1) * w + j; 
    				array[(i - 1) * w + j] = t;
    			}
    		}
    		//atkonvertalom a porszivo kezdo koordinatait egyetlen szamma
    		int porszivo_kezdo_csucs = (ho-1) * w + wo;
    		// ha nem minden pont erheto el a porszivo kezdpontjabol, akkor ki '-1' es ujjab iteracio
    		if(!Szeltkeres(0,porszivo_kezdo_csucs)){
    			cout << "-1" << endl;
    			cin >> w >> h;
    			continue;
    		}
    		//lefuttatom az osszes piszkos pontbol a szelessegi keresest
    		for(int i = 1; i <= dpnum; i++){
    			Szeltkeres(i,dirty_ps[i]);
    		}		
    		//a permutaciohoz letrehozok egy tombot
    		int dp_perm_ar[dpnum];
    		// a pertmutaciohoz ezt a tombot feltoltom
    		for(int i = 0; i < dpnum; i++){
    			dp_perm_ar[i] = i+1;
    		}
    		//kezdeti tavolsag vegtelen, res1: az aktualis menettav, amit a pertmutaciobol kapok
    		int res = 2000000000, res1 = 0;
    		//ha a piszkos foltok szama nagyobb mint 0
    		if(dpnum > 1){
    			do {
    				//a permutacios tomb segitsegevel - amit algorithm konyvtar segitsegevel szamolok - kiszamolom a
    				// legrovidebb menet tavolsagot
    				for(int i = 0; i<dpnum -1 ; i++){
    					res1 +=  dp_tav[dp_perm_ar[i]][dp_perm_ar[i + 1]];
    				}
    				res1 += dp_tav[0][dp_perm_ar[0]];
    				if(res1 < res) 
    					res = res1;
    				res1 = 0;
    			} while ( next_permutation(dp_perm_ar, dp_perm_ar+dpnum) );
    			cout << res << endl;
    		}else if( dpnum == 1){
    			res = 0;
    			res += dp_tav[0][dp_perm_ar[0]];
    			cout << res << endl;
    		}
    		else cout << '0' << endl;	
    		cin >> w >> h;	
    	}
    	return 0;
    }
     

