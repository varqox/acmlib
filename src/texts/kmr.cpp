VI S; // Text
// [...] fill S so that it contains the whole text
VVI kmr(1, S); // i-th row represents framgents of length 2**i
using IPI = pair<PII, int>;
V<IPI> v(S.size());
for (int step = 1; step * 2 <= (int)S.size(); step *= 2) {
	int k = (int)kmr.back().size() - step;
	REP (i, k)
		v[i] = {{kmr.back()[i], kmr.back()[i + step]}, i};
	/// Uncomment the below comments to make it O(n lg n) instead of O(n lg^2 n)
	v.resize(k);
	// if (step == 1)
	       sort(ALL(v), [](IPI& a, IPI& b) { return a.X < b.X; });
	// else
	// 	for (auto turn : {&PII::Y, &PII::X}) {
	// 		auto tmp = v;
	// 		int mx = k + step;
	// 		static VI cnt;
	// 		cnt.assign(mx + 1, 0);
	// 		for (auto&& p : v) ++cnt[p.X.*turn + 1];
	// 		REP (i, mx) cnt[i + 1] += cnt[i];
	// 		REP (i, k) v[cnt[tmp[i].X.*turn]++] = tmp[i];
	// 	}
	kmr.EB(VI(k));
	int id = 0;
	REP (i, k) {
		if (i and v[i].X != v[i - 1].X)
			++id;
		kmr.back()[v[i].Y] = id;
	}
}
// Compares two substrings
auto compare = [&](int a_beg, int a_len, int b_beg, int b_len) {
	int len = min(a_len, b_len);
	int k = 31 - __builtin_clz(len);
	PII ahash(kmr[k][a_beg], kmr[k][a_beg + len - (1 << k)]);
	PII bhash(kmr[k][b_beg], kmr[k][b_beg + len - (1 << k)]);
	if (ahash == bhash)
		return a_len < b_len; // shorter is lexicographically earlier
	return ahash < bhash;
};
// Id of the
auto get_id = [&](int beg, int len) {
	int k = 31 - __builtin_clz(len);
	return PII(kmr[k][beg], kmr[k][beg + len - (1 << k)]);
};
