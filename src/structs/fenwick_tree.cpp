// drzewo potegowe (+, suma)
#include <bits/stdc++.h>
using namespace std;


const int R = 1e5 + 10;
int drzewo[R];

void dodaj(int pozycja, int wartosc) {
    for ( ; pozycja <= R; pozycja += pozycja & -pozycja) {
        drzewo[pozycja] += wartosc;
    }
} 

int pytaj(int pozycja) {
    int wynik = 0;
    for ( ; pozycja > 0; pozycja -= pozycja & -pozycja) {
        wynik += drzewo[pozycja];
    }
    return wynik;
}

int suma(int poczatek, int koniec) {
    return pytaj(koniec) - pytaj(poczatek - 1);
}

int main() {
    dodaj(1, 1);
    dodaj(2, 2);
    dodaj(3, 3);
    dodaj(4, 4);
    dodaj(5, 5);
    dodaj(6, 6);
    
    cout << suma(3, 5) << endl;
        
    return 0;
}
