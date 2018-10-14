const LL mod = 1000000000000000003;

using LD = long double;

// brudne hacki
LL ilo1(LL val, LL n) {
	LL q = ((LD)val * (LD)n / (LD)mod);
	LL res = val * n - mod * q;
	res = (res % mod + mod) % mod;
	return res;
}

// mnozenie ruskich chlopow
LL ilo2(LL a, LL b) {
	LL res = 0;
	while (a != 0) {
		if (a & 1) {
			res += b;
			if (res >= mod)
				res -= mod;
		}
		a >>= 1;
		b <<= 1;
		if (b >= mod)
			b -= mod;
	}
	return res;
}

