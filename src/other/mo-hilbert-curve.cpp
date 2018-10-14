int ceil_log2(int x) {
	return x < 2 ? 0 : sizeof(x) * 8 - __builtin_clz(x - 1);
}

LL hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0)
		return 0;
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
	seg = (seg + rotate) & 3;
	const int rotate_delta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotate_delta[seg]) & 3;
	LL sub_square_size = 1ll << (2 * pow - 2);
	LL ans = seg * sub_square_size;
	LL add = hilbertOrder(nx, ny, pow - 1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (sub_square_size - add - 1);
	return ans;
}

struct MOQuery {
	int bg, ed, id;
	LL order;
	MOQuery(int _bg, int _ed, int _id, int _pow)
		: bg(_bg), ed(_ed), id(_id), order(hilbertOrder(_bg, _ed, _pow, 0)) {}
};

struct MOComp {
	bool operator()(const MOQuery &a, const MOQuery &b) const {
		return a.order < b.order;
	}
};

int main() {
	int n = 10;
	int pow = ceil_log2(n);
	
	V<MOQuery> qr;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		qr.EB(a, b, i, pow);
	}
	
	sort(ALL(qr), MOComp());
	
	int a = 0, b = -1;
	for (MOQuery &i : qr) {
		while (b < i.ed) b++;
		while (a > i.bg) a--;
		while (b > i.ed) b--;
		while (a < i.bg) a++;
	}
}