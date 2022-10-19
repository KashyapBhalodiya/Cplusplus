#include <bits/stdc++.h>

using namespace std;

int main() {

	// ------------------------------- Stack ------------------------------------

	// Empty, size, top, push, pop, emplace, swap

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << '\n';

	s.empty() == true ? cout << 1 << endl : cout << 0 << endl;

	stack<string> mystack;
	mystack.emplace("First");
	mystack.emplace("Second");

	while (!mystack.empty()) {
		cout << mystack.top() << " ";
		mystack.pop();
	}
	cout << '\n';

	// ------------------------------- Queue ------------------------------------

	// empty, size, front, back, push, emplace, pop, swap

	// ------------------------------ priority_queue ----------------------------

	// empty, size, top, push, pop, emplace, swap

	// min-heap is used to access the minimum element in the heap whereas the Max-heap 
	// is used when accessing the maximum element in the heap

	// minHeap : priority_queue<int, vector<int>, greater<int>> pq
	// maxHeap : priority_queue<int> pq;

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(10);
	pq.push(20);
	pq.push(30);

	cout << pq.size() << '\n';

	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << '\n';

	priority_queue<int> pq1;
	priority_queue<int> pq2;

	pq1.push(1);
	pq1.push(2);
	pq1.push(3);
	pq2.push(4);
	pq2.push(5);

	pq1.swap(pq2);

	cout << pq2.size() << " " << pq1.size() << '\n';
 	return 0;
}