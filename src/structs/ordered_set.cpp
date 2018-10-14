#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Cmp_Fn = less<Key>>
using ordered_set = tree<Key, null_type, Cmp_Fn, rb_tree_tag, 
                         tree_order_statistics_node_update>;


typedef pair<int, int> PII;
struct comp {
	bool operator()(const PII &a, const PII &b) const {
		return a.second == b.second ? a.first < b.first : a.second < b.second;
	}
};

int main() {
	ordered_set<PII, comp> s2;
	ordered_set<int> s;
	
	s.insert(1);
	s.insert(2);
	s.insert(4);
	s.insert(8);
	s.insert(16);

	cout << *s.find_by_order(1) << endl; // 2
	cout << *s.find_by_order(2) << endl; // 4
	cout << *s.find_by_order(4) << endl; // 16
	cout << (s.find_by_order(6) == s.end()) << endl; // true
	cout << endl;
	
	cout << s.order_of_key(-5) << endl;  // 0
	cout << s.order_of_key(1) << endl;   // 0
	cout << s.order_of_key(3) << endl;   // 2
	cout << s.order_of_key(4) << endl;   // 2
	cout << s.order_of_key(400) << endl; // 5
	cout << endl;
	
	s.erase(2);
	
	for (int i : s)
		cout << i << ' ';
	cout << endl;
	
	if (s.find(1) != s.end())
		s.clear();
}