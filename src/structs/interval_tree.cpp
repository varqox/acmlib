// drzewo przedział-przedział (+, max)
#include <bits/stdc++.h>
using namespace std;

const int R = 1 << 18;
int drzewo[2 * R], lazy[2 * R];

// przepychanie w dol
void update(int id, int wart) {
    drzewo[id] += wart;
    lazy[id] += wart;
}
void push(int id) {
    int lewy = 2 * id;
    int prawy = 2 * id + 1;
    
    update(lewy, lazy[id]);
    update(prawy, lazy[id]);
    
    lazy[id] = 0;
}

// maksimum na przedziale [pocz, kon]
int maks(int pocz, int kon, int id = 1, int l = 1, int p = R) {
    if (pocz > p) return -1e9;
    if (kon < l) return -1e9;
    
    if (pocz <= l && kon >= p) {
        return drzewo[id];
    }
    
    push(id);
    
    int lewy = 2 * id;
    int prawy = 2 * id + 1;
    int srodek = (l + p) / 2;
    return max(maks(pocz, kon, lewy, l, srodek),
                maks(pocz, kon, prawy, srodek + 1, p));
}

// dodaj wart do kazdej liczby na przedziale [pocz, kon]
void dodaj(int pocz, int kon, int wart, int id = 1, int l = 1, int p = R) {
    if (pocz > p) return;
    if (kon < l) return;
    
    if (pocz <= l && kon >= p) {
        update(id, wart);
        return;
    }
    
    push(id);
    
    int lewy = 2 * id;
    int prawy = 2 * id + 1;
    int srodek = (l + p) / 2;
    dodaj(pocz, kon, wart, lewy, l, srodek);
    dodaj(pocz, kon, wart, prawy, srodek + 1, p);
    
    drzewo[id] = max(drzewo[lewy], drzewo[prawy]);
}

int main() {
    dodaj(1, 3, 5);
    dodaj(2, 4, 7);
    dodaj(3, 5, -2);
    cout << maks(2, 4) << endl;
    dodaj(4, 5, 8);
    cout << maks(2, 4) << endl;
        
    return 0;
}
