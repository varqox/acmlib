// budowanie kodu prufera i odtwarzanie w O(n)
// Każdy wierzchołek x w kodzie Prufera pojawia się dokładnie deg(x) - 1 razy

// numeracja od 0
VVI v; // drzewo
VI par; // ojciec wierzcholka

void dfs(int a) {
	for (int u : v[a]) {
		if (u != par[a]) {
			par[u] = a;
			dfs(u);
		}
	}
}

VI prufer_encode() {
	int n = v.size();
	par.resize(n);
	par[n - 1] = -1;
	dfs(n - 1);

	int ptr = -1;
	VI deg(n);
	REP (i, n) {
		deg[i] = v[i].size();
		if (deg[i] == 1 && ptr == -1)
			ptr = i;
	}

	VI code(n - 2);
	int leaf = ptr;
	REP (i, n - 2) {
		int next = par[leaf];
		code[i] = next;
		if (--deg[next] == 1 && next < ptr) {
			leaf = next;
		}
		else {
			ptr++;
			while (deg[ptr] != 1)
				ptr++;
			leaf = ptr;
		}
	}

	return code;
}

// zwraca vector krawedzi
VPII prufer_decode(const VI &code) {
	int n = code.size() + 2;
	VI deg(n, 1);
	for (int i : code)
		deg[i]++;

	int ptr = 0;
	while (deg[ptr] != 1)
		ptr++;
	int leaf = ptr;

	VPII ed;
	for (int a : code) {
		ed.EB(leaf, a);
		if (--deg[a] == 1 && a < ptr) {
			leaf = a;
		}
		else {
			ptr++;
			while (deg[ptr] != 1)
				ptr++;
			leaf = ptr;
		}
	}
	ed.EB(leaf, n - 1);
	return ed;
}
