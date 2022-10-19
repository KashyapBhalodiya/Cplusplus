#include <bits/stdc++.h>
using namespace std;

// Maps are the associative containers that store sorted key-value pair, in which 
// each key is unique and it can be inserted or deleted but cannot be altered. 

// Constructor : empty, range, copy
// map<char, int> m1, map<char, int> m2(m1.begin(), m1.end()), map<char, int> m3(m1);

// Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
// capacity: size, empty, max_size
// Element access: at, []
// Modifiers: insert, erase, swap, clear, emplace, emplace_hint
// observers: key_comp, value_comp
// operations: find, count, lower_bound,upper_bound, equal_range

int main() {
	map<char, int> mymap;
	mymap['a'] = 101;

	cout << "size: " << mymap.size() << '\n' << "Max_size: " << mymap.max_size() << '\n';

	// insert
	mymap.insert(pair<char, int>('b', 102));
	for (auto it = mymap.begin(); it != mymap.end(); ++it) {
		cout << it->first << ' ' << it->second << endl;
	}

	// erase
	mymap.erase('b');
	for (auto it = mymap.begin(); it != mymap.end(); ++it) {
		cout << it->first << ' ' << it->second << endl;
	}	
	
	// swap
	map<char, int> mymap1;
	mymap1.insert(pair<char, int>('c', 103));
	mymap1.swap(mymap);
	cout << "Size mymap1: " << mymap1.size() << '\n';

	// emplace
	mymap1.emplace('x', 1000);
	mymap1.emplace('y', 2000);

	for (auto& x : mymap1) {
		cout << x.first << " " << x.second << endl;
	}

	// emplace_hint
	auto m = mymap.end();
	m = mymap.emplace_hint(m, 'd', 104);
	for (auto& x : mymap) {
		cout << x.first << ' ' << x.second << endl;
	}

	// key_comp
	map<char, int> m1;
	auto mycomp = m1.key_comp();
	m1['a'] = 101;
	m1['b'] = 102;
	m1['c'] = 103;

	char highest = m1.rbegin()->first;
	auto iter = m1.begin();

	do {
		cout << iter->first << " " << iter->second << endl;
	} while (mycomp((*iter++).first, highest));

	// value_comp

	pair<char, int> highest2 = *m1.rbegin();

	do {
		cout << iter->first << " " << iter->second << endl;
	} while (m1.value_comp()(*iter++, highest2));

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

	// lower_bound, upper_bound
	map<char, int> m2;
	m2['a'] = 10;
	m2['b'] = 20;
	m2['c'] = 30;
	m2['d'] = 40;
	m2['e'] = 50;

	map<char, int>::iterator low, up;
	low = m2.lower_bound('b');
	up = m2.upper_bound('d');

	m2.erase(low, up);

	for (auto& x : m2) {
		cout << x.first << " " << x.second << endl;
	}

	// equal_range
	auto ret = m2.equal_range('a');
	cout << ret.first->first << " " << ret.first->second << endl;
	cout << ret.second->first << " " << ret.second->second << endl;
	
	return 0;
}