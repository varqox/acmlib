// Max. flow in O(n^3) - push-relabel from http://code-library.herokuapp.com/preflow/java
VVI cap;

void init(int n) { cap.assign(n, VI(n)); }

void add_edge(int s, int t, int capacity) {
	cap[s][t] = capacity;
}
// capacities may be at most approximately 1.07e9
LL max_flow(int s, int t) {
	int n = (int)cap.size();
	VVI f(n, VI(n));
	VI maxh(n), e(n), h(n);
	h[s] = n - 1;

	REP (i, n) {
		f[i][s] = -(f[s][i] = cap[s][i]);
		e[i] = cap[s][i];
	}

	for (int sz = 0;;) {
		if (sz == 0) {
			REP (i, n)
				if (i != s and i != t and e[i] > 0) {
					if (sz and h[i] > h[maxh[0]])
						sz = 0;
					maxh[sz++] = i;
				}
		}

		if (sz == 0)
			break;

		while (sz) {
			int i = maxh[sz - 1];
			bool pushed = false;
			for (int j = 0; j < n and e[i]; ++j) {
				if (h[i] == h[j] + 1 and cap[i][j] - f[i][j] > 0) {
					int df = min(cap[i][j] - f[i][j], e[i]);
					f[i][j] += df;
					f[j][i] -= df;
					e[i] -= df;
					e[j] += df;
					if (e[i] == 0)
						--sz;
					pushed = true;
				}
			}

			if (not pushed) {
				h[i] = INT_MAX >> 1;
				REP (j, n)
					if (h[i] > h[j] + 1 and cap[i][j] - f[i][j] > 0)
						h[i] = h[j] + 1;
				if (h[i] > h[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}
	}

	LL flow = 0;
	REP (i, n)
		flow += f[s][i];
	return flow;
}