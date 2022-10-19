#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// Iterators:
	/*
		begin, end
		rbegin, rend-
		cbegin, cend
		crbegin, crend-
	*/

	// capacity: empty, max_size, size
	// element access: front, back-

	// modifiers
	/*
		assign
		emplace_front
		push_front
		pop_front
		emplace_back-
		push_back-
		pop_back-
		emplace-
		insert-
		erase-
		swap
		resize
		clear
	*/

	// operations
	/*
		splice
		remove
		remove_if
		unique
		merge
		sort
		reverse
	*/

	// To create a list there are 4 constructor:
	/*
		empty constructor (default constructor)
		fill constructor
		range constructor
		copy constructor
	*/

	list<int> first;
	list<int> second (4, 50);
	list<int> third (second.begin(), second.end());
	list<int> fourth (first);

	for (auto& x : first) cout << x << " ";
	cout << endl;

	for (auto& x : second) cout << x << " ";
	cout << endl;

	for (auto& x : third) cout << x << " ";
	cout << endl;

	for (auto& x : fourth) cout << x << " ";
	cout << endl;
	
}