LL cross(const PLL &a, const PLL &b, const PLL &c) {
	return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
}

V<PLL> convexHull(V<PLL> points) {
	if (SZ(points) <= 1)
		return points;
	sort(ALL(points));
	V<PLL> h;
	for (auto p: points) {
		while (SZ(h) >= 2 && cross(h.end()[-2], h.back(), p) >= 0)
			h.pop_back();
		h.EB(p);
	}
	reverse(ALL(points));
	int upper = SZ(h);
	for (auto p: points) {
		while (SZ(h) > upper && cross(h.end()[-2], h.back(), p) >= 0)
			h.pop_back();
		h.EB(p);
	}
	h.resize(SZ(h) - 1 - (h[0] == h[1]));
	return h;
}