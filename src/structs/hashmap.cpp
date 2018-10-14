#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
	int operator()(const PII &x) const {
		return x.first * 31 + x.second;
	}
};

int main() {
	// hash map
	gp_hash_table<PII, int, chash> t2;
	gp_hash_table<int, int> t;

	t[1] = 7;
	t.insert({2, 6});
	cout << t[1] << ' ' << t[2] << ' ' << t[3] << endl;
	if (t.find(1) != t.end())
		t.clear();
	cout << t.size() << ' ' << t.empty() << endl;
	

	// hash set	
	gp_hash_table<int, null_type> s;
	
	s[4]; // strange insert
	s.insert(3);
	cout << (s.find(3) == s.end()) << endl;
}