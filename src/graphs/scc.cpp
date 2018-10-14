int n, m, num;
VVI v, vr, vscc;
V<bool> odw;
VI st, col;
VVI wor;

void dfs(int a) {
	odw[a] = 1;
	for (int i : v[a])
		if (!odw[i])
			dfs(i);
	st.EB(a);
}

void dfsRev(int a) {
	col[a] = num;
	odw[a] = 1;
	for (int i : vr[a])
		if (!odw[i])
			dfsRev(i);
}

void findScc() {
	for (int i = 1; i <= n; i++)
		if (!odw[i])
			dfs(i);
	fill(ALL(odw), 0);
	REPD (i, SZ(st)) {
		if (!odw[st[i]]) {
			dfsRev(st[i]);
			num++;
		}
	}
	wor.resize(num);
	FOR (i, 1, n)
		wor[col[i]].EB(i);
}

void makeGraph() {
	vscc.resize(num);
	VI buf(num);
	for (auto &i : wor) {
		for (int j : i) {
			for (int k : v[j]) {
				if (!buf[col[k]] && col[k] != col[j]) {
					buf[col[k]] = 1;
					vscc[col[j]].EB(col[k]);
				}
			}
		}
		for (int j : i)
			for (int k : v[j])
					buf[col[k]] = 0;
	}
}

void init() {
	odw.resize(n + 1);
	col.resize(n + 1);
	v.resize(n + 1);
	vr.resize(n + 1);
}

int main() {
	cin >> n >> m;
	
	init();
	
	REP (i, m) {
		int a, b;
		cin >> a >> b;
		v[a].EB(b); // tworzymy graf podany na wejsciu
		vr[b].EB(a); // i drugi z odwroconymi krawedziami
	}
	
	// znajdujemy silnie spojne skladowe
	findScc();
	
	// jesli col[a] == col[b] to a i b sa w tej samej spojnej skladowej
	cerr << "Przynaleznosc wierzcholkow do silnie spojnych skladowych:" << endl;
	FOR (i, 1, n)
		cerr << i << ": " << col[i] << endl;
	cerr << endl;
	
	cerr << "Lista wierzcholkow w silnie spojnych skladowych:" << endl;
	REP (i, num) {
		cerr << i << ": ";
		for (int j : wor[i])
			cerr << j << ' ';
		cerr << endl;
	}
	cerr << endl;
	
	// tworzymy graf silnie spojnych skladowych
	makeGraph();
	
	cerr << "Graf silnie spojnych skladowych (lista sasiedztwa):" << endl;
	REP (i, num) {
		cerr << i << ": ";
		for (auto &j : vscc[i])
			cerr << j << ' ';
		cerr << endl;
	}
}
