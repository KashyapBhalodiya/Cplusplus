#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Forward lists are implemented as singly-linked lists

// Advantage:

// Forward lists are sequence containers that allow constant 
// time insert and erase operations anywhere within the sequence.
// No memory waste

// Disadvantage:

// More memory is required as compare to the array because a pointer also required to store the address
// Traversal is more time consuming as compared to the array
// reverse traversal not possible in singly linked list
// random access not possible due to its dynamic memory allocation

// How to create a forward_list ? 
//         > use empty container constructor (default constructor)
//         > use fill constructor
//         > use range constructor
//         > use copy constructor
//         > use initialiser list (C++11)

// iterators: before_begin, begin, end, cbefor_begin, cbegin, cend
// capacity: empty, max_size
// Element access: front
// modifiers: assign, emplace_front, push_front, pop_front, emplace_after, 
//            insert_after, erase_after, swap, resize, clear
// Operations: splice_after, remove, remove_if, unique, merge, sort, reverse
bool foo (int n) {
    return (n > 5);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Code

    // forward_list<int> first; // default OR empty
    // forward_list<int> second(3, 77); // fill
    // forward_list<int> third(second.begin(), second.end()); // range
    // forward_list<int> fourth(third); // copy
    // forward_list<int> fifth = {3, 52, 25, 90}; // initialiser
    
    forward_list<int> fl = {1,2,3,4,5};

    // Iterators:

    fl.insert_after(fl.before_begin(), 10); // iterator to the position before the beginning of the sequence
    // all use cbefore_begin() this is constant element
    for (int& x : fl) cout << x << " ";
    cout << "\n";

    for (auto i = fl.begin(); i != fl.end(); ++i) 
        cout << *i << " ";
    cout << "\n";

    for (auto i = fl.cbegin(); i != fl.cend(); ++i)
        cout << *i << " ";
    cout << "\n";

    cout << "Empty: " << fl.empty() << "\n";
    cout << "Max size: " << fl.max_size() << "\n";
    cout << "Front: " << fl.front() << "\n";

    forward_list<int> first;
    forward_list<int> second;
    forward_list<int> third;

    first.assign(6, 15);
    second.assign(first.begin(), first.end());
    third.assign({1,2,3,4,5});

    for (int& x : first) cout << x << " ";
    cout << "\n";
    for (int& x : second) cout << x << " ";
    cout << "\n";
    for (int& x : third) cout << x << " ";
    cout << "\n";
    
    cout << "emplace_front and emplace_after:\n";

    forward_list<pair<int, char>> mylist;
    mylist.emplace_front(10, 'a');
    mylist.emplace_front(20, 'b');
    mylist.emplace_front(30, 'c');

    auto it = mylist.before_begin();

    it = mylist.emplace_after(it, 10, 'e');
    it = mylist.emplace_after(it, 20, 'f');
    it = mylist.emplace_after(it, 30, 'g');

    for (auto& x : mylist) cout << x.first << " " << x.second << "\n";

    fl.push_front(12);
    for (auto& x : fl) cout << x << " ";
    cout << endl;
    fl.pop_front();
    for (auto& x : fl) cout << x << " ";
    cout << endl;

    fl.erase_after(fl.begin(), fl.end());
    for (auto& x : fl) cout << x << " ";
    cout << endl;

    first.swap(second);
    for (auto& x : first) cout << x << " ";
    cout << endl;

    fl.resize(5);
    // fl.resize(5, 100);
    for (auto& x : fl) cout << x << " ";
    cout << endl;    

    // Clear
    fl.clear();

    // spice_after(position, forward_list, iterator)
    cout << "splice_after: \n";
    forward_list<int> f1 = {1,2,3,6};
    forward_list<int> f2 = {1,3,4,5};

    f2.splice_after(f2.begin(), f1, f1.begin());
    for (auto& x : f2) cout << x << " ";
    cout << endl;

    cout << "remove: \n";
    f1.remove(1);
    for (auto& x : f1) cout << x << " ";
    cout << endl;

    // remove_if 
    cout << "remove_if: \n";
    f1.remove_if(foo);
    for (auto& x : f1) 
        cout << x << " ";
    cout << endl;

    // remove duplicates elements sorted order use unique function
    cout << "unique:\n";
    forward_list<int> f3 = {1,1,2,2,3,4,4,5};
    f3.unique();
    for (auto& x : f3) cout << x << " ";
    cout << endl;

    cout << "merge:\n";
    f1.merge(f2);
    for (auto& x : f1) cout << x << " ";
    cout << endl;

    cout << "sort by default:";
    f1.sort();
    for (auto& x : f1) cout << x << " ";
    cout << endl;

    cout << "sort greater order:";
    f1.sort(greater<int>());
    for (auto& x : f1) cout << x << " ";
    cout << endl;

    cout << "reverse: ";
    f1.reverse();
    for (auto& x : f1) cout << x << " ";
    cout << endl;
    
    return 0;
}