struct point {
	LL x, y;
	point(LL _x = 0, LL _y = 0)
		: x(_x), y(_y) {}
};

ostream& operator<<(ostream &ost, const point &p) {
	return ost << '(' << p.x << ',' << p.y << ')';
}

// iloczyn wektorowy - dodatni jezeli sciezka a -> b -> c skreca w lewo,
// ujemny jesli skreca w prawo,
// zerowy kiedy idzie prosto (lub zawraca o 180 stopni)
LL left(const point &a, const point &b, const point &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

struct comp {
	point a;
	comp(point _a) 
		: a(_a) {}
	
	bool operator()(const point &b, const point &c) const {
		LL tm = left(a, b, c);
		if (tm == 0)
			return b.x - a.x + b.y - a.y < c.x - a.x + c.y - a.y;
		return tm > 0;
	}
	
};

V<point> convexHull(V<point> pt) {
	int n = pt.size();
	if (n <= 3)
		return pt;
	
	// znajdujemy najnizszy punkt i sortujemy katowo wzgledem niego
	FOR (i, 1, n - 1)
		if (pt[i].y < pt[0].y)
			swap(pt[i], pt[0]);
	sort(pt.begin() + 1, pt.end(), comp(pt[0]));
	
	// znajdujemy otoczke wypukla
	V<point> res = {pt[0], pt[1]};
	FOR (i, 2, n - 1) {
		while (left(res[res.size() - 2], res.back(), pt[i]) < 0)
			res.pop_back();
		res.emplace_back(pt[i]);
	}
	
	return res;
}

// liczenie pola za pomoca iloczynu wektorowego
double getArea(const V<point> &pt) {
	LL res = 0;
	REP (i, SZ(pt))
		res += left(point(0, 0), pt[i], pt[(i + 1) % pt.size()]);
	return abs((double)res / 2);
}

int main() {
	int n;
	cin >> n;
	V<point> v(n);
	
	REP (i, n)
		cin >> v[i].x >> v[i].y;
	
	auto res = convexHull(v);
}
