#include <bits/stdc++.h>
using namespace std;

LL P = 1237, MOD = 1000000009;
VLL pot, hasz;

LL query(int a, int b) {
	if (a == 0)
		return hasz[b];
	return (hasz[b] - hasz[a - 1] * pot[b - a + 1] + MOD * MOD) % MOD;
}

void init(const string &s) {
	int len = s.size();
	pot.resize(len);
	hasz.resize(len);
	
	pot[0] = 1;
	FOR (i, 1, len - 1)
		pot[i] = (pot[i - 1] * P) % MOD;
	
	hasz[0] = s[0];
	FOR (i, 1, len - 1)
		hasz[i] = (hasz[i - 1] * P + s[i]) % MOD;
}