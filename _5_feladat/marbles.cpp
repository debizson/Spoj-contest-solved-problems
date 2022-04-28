
/* https://www.spoj.com/problems/MARBLES/ */

/* Az algoritmus magyarazata reszletesen a videoban!

Dinnyes Balazs Gazdasaginformatikus Bsc nappali hallgato ACM versenyfeladatok megoldasa kurzushoz, az 5. feladat

A feladat nev: Marbles

A feladat : Hanschen arról almodik, hogy egy boltban minden szinu marvanybol vegtelen szamu marvany van. k db tipusu marvany van 
a boltban es n db - ot akar kivalasztani. Ez eddig az ismetleses kombinacio egy peldaja, de a problema annyival nehezebb, hogy 
a valasztasnal Hanschen minden tipusbol legalabb egyet szeretne kivalasztani. Egy ismetleses kombinacio esete ez tehat,
 mert ismetleses mert minden fajtabol vegtelen szamu van, az azonos fajtakat(szinueket) nem kulonboztetjuk meg egymastol sehogyan 
 és a sorrendje a valasztasnak nem szamit, ezért beszelunk kombinaciorol.
 
 Az alap keplet az a kovetkezo lenne: (n + k -1)C(k - 1) de mivel minden fajtabol kell valasztani legalabb egyet Hanschennek
 ezert a keplet ((n-k)+k-1)C(k-1) =>  (n-1)C(k-1) - ra modosul.

Input adatok: elso adat a sorban az n kivalasztas, a masodik a k fajta szama.

Output - ra kombinaciok szama.

Input:
2
10 10
30 7

Output:
1
475020

*/ 
 
 
#include <stdio.h>

int main() {

  int testcases;
  scanf("%d", &testcases);

  while (testcases--) {
    
    unsigned int n, k;
    scanf("%u %u", &n, &k);

    unsigned long long int res = 1;
    // Az(n-1)C(k-1) kiszamitasa ciklussal, mert faktorialis reszletek kiszamitasa a feladat
    for (unsigned int i = 1; i < k; i++)
      res = res * (n-k+i) / i;

    printf("%llu\n", res);
  }

  return 0;
}
