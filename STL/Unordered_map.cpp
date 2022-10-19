#include <bits/stdc++.h>
using namespace std;

// Unordered map is an associative container that contains key-value pairs with unique keys. 

// constructor: empty, range, copy, move, initialize

// capacity: empty, size, max_size
// iterator: begin, end, cbegin, cend
// element access: at, []
// element lookup: find, count, equal_range
// modifiers: emplace, emplace_hint, insert, erase, swap, clear
// Buckets: bucket_count, max_bucket_count, bucket_size, bucket
// Hash policy: load_factor, max_load_factor, rehash, reserve
// observers: hash_function, key_eq, get_allocator

int main() {
	unordered_map<string, double> mymap = {{"milk", 3.2}, {"eggs", 0.40}};
	cout << "size: " << mymap.size() << endl << "max_size: " << mymap.max_size() << endl;

	unordered_map<char, int> m1;
	m1.insert({{'a', 100}, {'b', 200}, {'c', 300}});

	// find
	auto f = m1.find('b');
	if (f != m1.end()) {
		m1.erase(f);
	}
	for (auto& x : m1) {
		cout << x.first << " " << x.second << endl;
	}

	// count
	char ch;
	for (ch = 'a'; ch < 'e'; ch++) {
		if (m1.count(ch) > 0) {
			cout << ch << " is element\n";
		} else {
			cout << ch << " not element\n";
		}
	}

	// equal_range
	auto ret = m1.equal_range('a');
	cout << ret.first->first << " " << ret.first->second << endl;
	cout << ret.second->first << " " << ret.second->second << endl;
	
	// emplace
	m1.emplace('d', 400);
	for (auto& x : m1) {
		cout << x.first << " " << x.second << endl;
	}

	// emplace_hint
	m1.emplace_hint(m1.begin(), 'e', 500);
	for (auto itr = m1.begin(); itr != m1.end(); itr++)
        cout << itr->first << "\t" << itr->second << endl;

	// erase
    m1.erase(m1.begin());

    // bucket_count
    unsigned n = m1.bucket_count();
    for (unsigned i=0; i<n; ++i) {
    	cout << i << " ";
    }
    cout << '\n';

    // max_bucket_count
    cout << m1.max_bucket_count() << '\n';

    // bucket_size
    for (unsigned i=0; i<n; ++i) {
    	cout << m1.bucket_size(i) << '\n';
    }

    // bucket
    for (auto& x : m1) {
    	cout << m1.bucket(x.first) << '\n';
    }

    // load_factor
    cout << m1.load_factor() << '\n';

    // max_load_factor
    cout << m1.max_load_factor() << '\n';

    // rehash
    m1.rehash(20);
    cout << m1.bucket_count() << '\n';

    // reserve
    m1.reserve(2);
    m1['a'] = 101;
    m1['b'] = 102;

    for (auto& x : m1) {
    	cout << x.first << " : " << x.second << endl;
    }

    unordered_map<string, string> m2;

    // hash_function
    auto fn = m2.hash_function();

    cout << fn("this") << '\t' << fn("thin") << endl;

    // key_eq
    bool case_insensitive = m2.key_eq()("test","TEST");

	cout << ( case_insensitive ? "case insensitive" : "case sensitive" );


	return 0;
}