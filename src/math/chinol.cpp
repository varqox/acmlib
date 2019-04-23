inline LL fast_mod(LL a, LL mod) {
	return a >= mod ? a - mod : a;
	// return a % mod;
}

inline LL mul(LL u, LL v, LL p) noexcept {
    return(u * v-(LL)((long double)u * v / p) * p + p ) % p;
}

// Binary multiply (ruskie chłopy)
// inline LL mul(LL a, LL b, LL mod) {
// 	// return __int128(a) * b % mod;
// 	// LOG(a) imie(b);
// 	if (b == 1)
// 		return a;

// 	if (b & 1)
// 		return fast_mod(a + mul(a, b - 1, mod), mod);

// 	LL x = mul(a, b >> 1, mod);
// 	return fast_mod(x + x, mod);
// }

inline LL power(LL a, LL k, LL mod) {
	LL res = 1;
	while (k) {
		if (k & 1)
			res = mul(res, a, mod);

		a = mul(a, a, mod);
		k >>= 1;
	}

	return res;
}

inline LL power2(LL a, LL k, LL mod) {
	LL res = 1;
	while (k) {
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}

	return res;
}

inline pair<LL, LL> rnwd(LL a, LL b) {
	if (b == 0)
		return {1, 0};
	LL x, y;
	tie(x, y) = rnwd(b, a % b);
	return {y, x - a / b * y};
}

LL chinol(LL x1, LL x2, LL m1, LL m2) {
	LL x = x1;
	LL y = x2;
	LL a = m1;
	LL b = m2;
	LL m = m1 * m2;
	return (mul(y, rnwd(a, b).first * a, m) + mul(x, rnwd(b, a).first * a, m)) % m;
}
