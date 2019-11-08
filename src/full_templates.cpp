#pragma GCC optimize("O3")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for (auto i ## __ = (n), i = (a); i <= i ## __; ++i)
#define FORD(i,a,n) for (auto i ## __ = (n), i = (a); i >= i ## __; --i)
#define REP(i,n) FOR(i,0,(n) - 1)
#define ALL(h) begin(h), end(h)
#define EB emplace_back
#define X first
#define Y second
#define V vector
#define tpv typedef V<

typedef long long LL;
typedef pair<int, int> PII;
tpv int> VI;
tpv VI> VVI;
tpv PII> VPII;
tpv LL> VLL;

constexpr char nl = '\n';
#define endl nl
#define ris return *this
#define tem template<class t

tem, class u> inline void mini(t& a, u&& b) { if (b < a) a = b; }
tem, class u> inline void maxi(t& a, u&& b) { if (b > a) a = b; }
int ceil2(int h) { return h < 2 ? 1 : 1 << (sizeof(h) * 8 - __builtin_clz(h - 1)); }

tem> struct Dump { t a, b; };
tem> auto dump(t&& h) -> Dump<decltype(begin(h))> { return {ALL(h)}; }
tem> auto stub(t* h) -> decltype(cerr << *h, 0);
tem> char stub(...);
#define enif(o) tem> typename enable_if<sizeof stub<t>(0) o 1, debug&>::type operator<<(t h)
#define dor > debug& operator<<
struct debug {
#ifdef DEBUG
#define deb debug()
	~debug() { cerr << nl; }
	enif(!=) { cerr << boolalpha << h; ris; }
	enif(==) {
		*this << '{';
		for (auto a = begin(h), b = end(h); a != b;)
			*this << *a++ << &" "[a == b];
		ris << '}';
	}
	tem, class u dor(pair<t, u> p) { ris << '(' << p.X << ", " << p.Y << ')'; }
	tem dor(Dump<t> d) {
		*this << "{\n";
		for (t a = d.a, c = a; a != d.b; ++a)
			*this << "  " << distance(c, a) << ": " << *a << nl;
		ris << '}';
	}
#else
	operator int() { return 0; }
	tem dor(t&&) { ris; }
#define deb 0 and debug()
#endif
};

#define imie(h...) #h ": " << (h) << " "
#define LOG(h...) deb << imie(h)
#define DOG(h...) deb << #h ": " << dump(h) << " "

long long inv(long long a, long long m){
	return 1<a ? m - inv(m%a,a)*m/a : 1;
}

using point = complex<long double>;

inline point::value_type dot(point a, point b) noexcept {
	return (conj(a) * b).real();
}

inline point::value_type cross(point a, point b) noexcept {
	return (conj(a) * b).imag();
}

inline point::value_type dist(point a, point b) noexcept {
	return abs(a - b);
}

inline point normalized(point a) noexcept {
	return a / abs(a);
}

inline ostream& operator<<(ostream& os, point p) noexcept {
	return os << '(' << p.real() << ' ' << p.imag() << ')';
}

struct Line {
	point dir;
	point shift;
	// goes through shift and shift + dir

	Line() : Line(point(0, 0), point(1, 1)) {}

	// a ---> b
	Line(point a, point b) : dir(b - a), shift(a) {}

	Line& shift_to_through(point p) {
		shift = p;
		return *this;
	}

	// Rotates by theta (shift still lies on the line)
	Line& rotate(long double theta) {
		dir = dir * polar(1.0l, theta);
		return *this;
	}
};

inline point intersection(point a, point b, point p, point q) noexcept {
  long double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

inline point intersection(Line a, Line b) noexcept {
	return intersection(a.shift, a.shift + a.dir, b.shift, b.shift + b.dir);
}

inline ostream& operator<<(ostream& os, Line l) noexcept {
	return os << '(' << l.shift << ' ' << l.shift + l.dir << ')';
}

inline point project(point p, Line l) noexcept {
	p -= l.shift;
	p = l.dir * dot(p, l.dir) / norm(l.dir);
	return p += l.shift;
}

struct IntPoint {
	int x, y;

	IntPoint(int a, int b) : x(a), y(b) {}

	IntPoint(PII p) : IntPoint(p.X, p.Y) {}

	IntPoint& operator+=(IntPoint a) noexcept {
		x += a.x;
		y += a.y;
		return *this;
	}

	IntPoint& operator-=(IntPoint a) noexcept {
		x -= a.x;
		y -= a.y;
		return *this;
	}

	operator point() const noexcept { return point(x, y); }
};

inline IntPoint operator+(IntPoint a, IntPoint b) noexcept {
	return {a.x + b.x, a.y + b.y};
}

inline IntPoint operator-(IntPoint a, IntPoint b) noexcept {
	return {a.x - b.x, a.y - b.y};
}

inline long long dot(IntPoint a, IntPoint b) noexcept {
	return LL(a.x) * b.x + LL(a.y) * b.y;
}

inline long long cross(IntPoint a, IntPoint b) noexcept {
	return LL(a.x) * b.y - LL(a.y) * b.x;
}

ostream& operator <<(ostream& os, const IntPoint& x) {
	return os << "(" << x.x << ' ' << x.y << ")";
}

struct IntLine {
	IntPoint dir;
	IntPoint shift;
	// goes through shift and shift + dir

	IntLine() : IntLine(IntPoint(0, 0), IntPoint(1, 1)) {}

	// a ---> b
	IntLine(IntPoint a, IntPoint b) : dir(b - a), shift(a) {}

	IntLine& shift_to_through(IntPoint p) {
		shift = p;
		return *this;
	}

	operator Line() { return Line(shift, dir + shift); }
};

inline point intersection(IntLine a, IntLine b) noexcept {
	return intersection(a.shift, a.shift + a.dir, b.shift, b.shift + b.dir);
}

inline ostream& operator<<(ostream& os, IntLine l) noexcept {
	return os << '(' << l.shift << ' ' << l.shift + l.dir << ')';
}

inline int sgn(LL x) { return (x < 0 ? -1 : (x > 0 ? 1 : 0)); }

template<class T>
decltype(cross(T(), T())) area(const V<T>& v) {
	decltype(cross(T(), T())) res {};
	auto prev = v.back();
	for (auto const& p : v)
		res += cross(prev, p), prev = p;

	return abs(res);
}

// constexpr long double EPS = 1e-8;

// constexpr int mod = 1000*1000*1000 + 7;
constexpr int mod = 123456789;

class Matrix {
public:
	int n, m;
	vector<LL> t;

	Matrix(int k, int l) : n(k), m(l), t(k * l) {}

	const LL* operator[](int k) const { return t.data() + k * m; }

	LL* operator[](int k) { return t.data() + k * m; }

	Matrix operator*(const Matrix& x) {
		assert(m == x.n);
		Matrix res(n, x.m);
		REP (i, n)
			REP (k, x.m)
				REP (j, m)
					res[i][j] += (*this)[i][k] * x[k][j] % mod;

		REP (i, n)
			REP (j, m)
				res[i][j] %= mod;

		return res;
	}
};

Matrix pow(Matrix x, LL k) {
	Matrix res(x.n, x.m);
	REP (i, x.n)
		res[i][i] = 1;

	while (k) {
		if (k & 1)
			res = res * x;
		x = x * x;
		k >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	return 0;
}


/*

*/
