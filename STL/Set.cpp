#include <bits/stdc++.h>
using namespace std;

/*
	Set and Multiset: 
	set the keys must be unique, while a multiset permits duplicate keys.
*/

// NOTE : Both set and multiset operations are same.

// Set is a container that is used to store the values which are unique

// Constructor: empty, range, copy
// set<int> first, set<int> second(first.begin(), first.end()) , set<int> third(first);

// Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
// capacity: size, empty, max_size
// modifiers: insert, erase, swap, clear, emplace, emplace_hint
// observers: key_comp, value_comp
// operattions: find, count ,lower_bound, upper_bound, equal_range

int main() {
	set<int> myset;
	myset.insert(100);
	cout << "size: " << myset.size() << endl << "max_size: " << myset.max_size() << endl;

	set<int>::iterator it = myset.begin();
	myset.erase(it);

	set<int> s;
	for (int i=1; i<=5; i++)
		s.insert(i * 10);

	s.swap(myset);

	for (auto it = myset.begin(); it != myset.end(); it++) {
		cout << *it << ' ';
	}
	cout << '\n';

	s.emplace(10);
	s.emplace(20);
	
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << '\n';


	// insert unique elements in a set at a desired position while maintaining the ascending order property of the set
	set<string> s1;
	auto it1 = s1.cbegin(); // constant means sort the order

	s1.emplace_hint(it1, "aplha");
	it1 =s1.emplace_hint(s1.cend(),"omega");
	it1 =s1.emplace_hint(it1,"epsilon");
	it1 =s1.emplace_hint(it1,"beta");

	for (const string& x : s1) {
		cout << x << ' ';
	}
	cout << '\n';

	// key_comp: used to return a copy of the comparison object
	set<int> s2;
	set<int>::key_compare comp = s2.key_comp();

	cout << comp(1, 5) << '\n';
	cout << comp(3, 2) << '\n';

	// value_comp: returns a copy of the comparison object used by the container
	set<int>::value_compare comp2 = s2.value_comp();

	cout << comp2(2, 5) << '\n';
	cout << comp2(8, 5) << '\n';

	// find
	myset.erase(myset.find(10));
	for (auto& x : myset) {
		cout << x << " ";
	}

	int arr[] = {1,2,3,4,5};
	set<int> s3(arr, arr+5);

	if (s3.count(3)) cout << "\nYES\n";
	else cout << "\nNO\n";

	// lower_bound() = used to return an iterator pointing to the first element in the 
	// range [first, last) which has a value not less than val
	
	// upper_bound() = returns an iterator to the upper bound of the value whose upper bound we wish to find.

	set<int> s4;
	set<int>:: iterator low, up;

	for (int i=1; i<10; ++i) s4.insert(i * 10);

	up = s4.upper_bound(60);
	low = s4.lower_bound(30);

	s4.erase(low, up);

	for (auto i=s4.begin(); i != s4.end(); ++i) {
		cout << *i << ' ';
	}
	cout << '\n';

	// equal_range() = returns an iterator of pairs.

	auto ret = s4.equal_range(20);
	cout << "Lower point: " << *ret.first << "\nUpper point: " << *ret.second << '\n'; 
	return 0;
}