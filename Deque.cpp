#include <bits/stdc++.h>

using namespace std;

int main() {
	// Iterators: begin, end, cbegin, cend, crend, crbegin, rbegin, rend
	// capacity: size, max_size, resize, empty, shrink_to_fit
	// Element access: at, front, back
	// modifiers: assign, push_back, pop_back, push_front, pop_front, insert, erase, swap, clear
	// 			  emplace, emplace_front, emplace_back


	/*
		Constructors: Empty, fill, range, copy
	*/

	deque<int> first;
	deque<int> second(4, 100);
	deque<int> third(second.begin(), second.end());
	deque<int> fourth(second);

	deque<int> dq(5);
	cout << "Size: " << dq.size() << '\n';
	dq.resize(8);
	cout << "Size: " << dq.size() << '\n';
	dq.shrink_to_fit(); // hich reduces the capacity of the container to fit its size and destroys all elements beyond the capacity

	dq.push_front(1);
	dq.push_back(2);

	cout << dq.front() << " " << dq.back();  
	
	dq.pop_front();
	dq.pop_back();

	cout << '\n';
	
	dq.assign(6, 100);
	for (auto& x : dq) {
		cout << x << " ";
	}
	cout << '\n';
	
	// auto
	deque<int>::iterator it = dq.begin();

	// iteration position, size, value
	dq.insert(it, 2, 20);

	for (int& x : dq) {
		cout << x << ' ';
	}
	cout << '\n';

	dq.erase(dq.begin(), dq.begin() + 2);
	for (int& x : dq) {
		cout << x << ' ';
	}
	cout << '\n';

	dq.swap(second);
	for (int& x : dq) {
		cout << x << ' ';
	}
	cout << '\n';

	// emplace: used to insert or emplace a new element in the queue container.
	deque<int> mydeque = {10, 20, 30};
	auto ti = mydeque.emplace(mydeque.begin() + 1, 50);
	mydeque.emplace(ti, 60);

	for (int& x : mydeque) {
		cout << x << ' ';
	}
	cout << '\n';

	// emplace_front: used to insert a new element into the deque container at the beginning.
	mydeque.emplace_front(111);
  	mydeque.emplace_front(222);

  	for (int& x : mydeque) {
		cout << x << ' ';
	}
	cout << '\n';

	// emplace_back: used to insert a new element into the deque container at the end.
	mydeque.emplace_back(111);
  	mydeque.emplace_back(222);

  	for (int& x : mydeque) {
		cout << x << ' ';
	}
	cout << '\n';


}