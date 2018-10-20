VVI v;
V<bool> vis;
VI match; // match[i] - id wierzcholka skojarzonego z i, -1 jesli nie skojarzony

bool dfsMatch(int a) {
	vis[a] = true;
	for (int i : v[a]) {
		if (match[i] == -1 || (!vis[match[i]] && dfsMatch(match[i]))) {
			match[a] = i;
			match[i] = a;
			return true;
		}
	}
	return false;
}

// zwraca liczbe skojarzonych wierzcholkow
// numeracja grafu od 0
// n - liczba wierzcholkow
int turboMatching(int n) {
	VI(n, -1).swap(match);
	vis.resize(n);
	bool better = 1;
	int res = 0;
	while (better) {
		better = 0;
		fill(ALL(vis), 0);
		REP (i, n) {
			if (match[i] == -1 && !vis[i] && dfsMatch(i)) {
				better = 1;
				res += 2;
			}
		}
	}
	return res;
}

// miesza krawedzie w grafie, zeby TB sie nie kwadracil przy wrednych testach
void shuffleGraph() {
	for (auto &i : v)
		random_shuffle(ALL(i));
}
