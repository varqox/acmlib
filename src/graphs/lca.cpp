constexpr int N = 21;
VVI v, jump;
VI dep;

void init(int n) {
	v.resize(n + 1);
	jump.resize(n + 1, VI(N));
	dep.resize(n + 1);
}

void prepare(int a, int prev) {
	jump[a][0] = prev;
	FOR (i, 1, N - 1)
		jump[a][i] = jump[jump[a][i - 1]][i - 1];
	for (int i : v[a]) {
		if (i != prev) {
			dep[i] = dep[a] + 1;
			prepare(i, a);
		}
	}
}

int jumpUp(int a, int sub) {
	int len = 0;
	while (sub != 0) {
		if (sub % 2)
			a = jump[a][len];
		len++;
		sub /= 2;
	}
	return a;
}

int lca(int a, int b) {
	if (dep[a] < dep[b])
		swap(a, b);
	
	a = jumpUp(a, dep[a] - dep[b]);
	
	if (a == b)
		return a;
	
	FORD (i, N - 1, 0) {
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	}
	return jump[a][0];
}

int main() {
	int n;
	cin >> n;
	
	init(n);
	
	REP (i, n - 1) {
		int a, b;
		cin >> a >> b;
		v[a].EB(b);
		v[b].EB(a);
	}
	
	int root = 1;
	prepare(root, root);
}
