// lp[i] - najmniejszy dzielnik liczby i
// phi[i] - phi od i
// pr - vector liczb pierwszych
VI lp, phi, pr;

void sieve(int N) {
	lp.resize(N + 1);
	phi.resize(N + 1);
	
	phi[1] = 1;
	FOR (i, 2, N) {
		if (lp[i] == 0) {
			lp[i] = i;
			phi[i] = i - 1;
			pr.EB(i);
		}
		else {
			if (lp[i] == lp[i / lp[i]])
				phi[i] = phi[i / lp[i]] * lp[i];
			else
				phi[i] = phi[i / lp[i]] * (lp[i] - 1);
		}
		for (int j = 0; j < SZ(pr) && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}