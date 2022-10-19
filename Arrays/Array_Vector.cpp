#include <bits/stdc++.h>
using namespace std;

/*  Vector
    Iterators: begin, end, cbegin, cend, crbegin, crend, rbegin, rend

    Capacity: size, max_size, empty, resize, capacity, reserve, shrink_to_fit

    Element access: front, back, at, data

    Modifiers: fill, swap, assign, push_back, pop_back, insert, erase, swap, clear, emplace, emplace_back
*/

/*  Arrays
    Iterators: begin, end, cbegin, cend, crbegin, crend, rbegin, rend

    Capacity: size, max_size, empty

    Element access: front, back, at, data, operator[]

    Modifiers: swap, fill
*/

int main() {
/* Fill in array
    array<int, 6> a;
    a.fill(5);
    for (auto& x : a) {
        cout << x << ' ';
    }
*/

/*------------------------------------------ vector ----------------------------------------------*/

	// Iterators

	vector<int> v{1,2,3,4,5};

	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}
	
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        cout << *i << " ";
    }
    cout << "\n";

    // cbegin and cend mean constant
    for (auto i = v.cbegin(); i != v.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "\n";

    for (auto i = v.crbegin(); i != v.crend(); ++i) {
        cout << *i << " ";
    }
    cout << "\n";

    // Capacity

    cout << "Vector size: " << v.size() << " and capacity: " << v.capacity() << "\n";

    cout << "Max size: " << v.max_size() << "\n" << "Vector is empty or not: " << (v.empty() == 0) << "\n";

    cout << "Resize: ";
    v.resize(10);
    cout << v.capacity() << endl;

    cout << "Reserve: ";
    v.reserve(100);
    cout << v.capacity() << endl;

    cout << "shrink to fit: "; // Requests the container to reduce its capacity to fit its size.
    v.shrink_to_fit();
    cout << v.capacity() << "\n";

    // Element access

    for (int i=0; i<v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << "\n";

    cout << "Front: " << v.front() << " and back: " << v.back() << endl; 

    // Modifiers

    v.assign(2, 0); // assigns new values to the vector elements by replacing old ones
    // v.assign(v, v + 2);
    // v.assign(v.begin(), v.begin() + 3)
    // v.assign({ 1, 2, 3 });
    for (int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << "\n";

    v.push_back(1);
    v.pop_back();

    auto it = v.insert(v.begin(), 5);
    v.insert(it, 2);
    for (int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << "\n";

    v.erase(v.begin() + 2);
    for (int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << "\n";

    vector<int> myvector1{ 1, 2, 3, 4 };
    vector<int> myvector2{ 3, 5, 7, 9 };
 
    myvector1.swap(myvector2);
    for (int i=0; i<v.size(); ++i){
        cout << myvector1[i] << " ";
    }
    cout << "\n";

    v.clear();

    vector<int> vec = { 10, 20, 30 };

    auto v1 = vec.emplace(vec.begin(), 15);
    for (auto v1 = vec.begin(); v1 != vec.end(); ++v1)
        cout << *v1 << " ";
    cout << "\n";

    vec.emplace_back(40);
    vec.emplace_back(50);
    for (auto v1 = vec.begin(); v1 != vec.end(); ++v1)
        cout << *v1 << " ";
    cout << "\n";

	return 0;
}