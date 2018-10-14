uint readUInt() {
	char c = ' ';
	while (c < '0' || c > '9')
		c = getchar_unlocked();
	uint res = 0;
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar_unlocked();
	}
	return res;
}

int readInt() {
	char c = ' ';
	while ((c < '0' || c > '9') && c != '-')
		c = getchar_unlocked();
	int res = 0, zn = 1;
	if (c == '-') {
		zn = -1;
		c = getchar_unlocked();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar_unlocked();
	}
	return res * zn;
}

double readDouble() {
	char c = ' ';
	while ((c < '0' || c > '9') && c != '-')
		c = getchar_unlocked();
	double res = 0, zn = 1;
	if (c == '-') {
		zn = -1;
		c = getchar_unlocked();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar_unlocked();
	}
	if (c == '.') {
		c = getchar_unlocked();
		double div = 10;
		while (c >= '0' && c <= '9') {
			res += (c - '0') / div;
			div *= 10;
			c = getchar_unlocked();
		}
	}
	return res * zn;
}
