#include <bits/stdc++.h>
using namespace std;

// Unordered_set: unordered_set is a set in which key can be stored in any order

// Constructor: empty, range, copy, move, intializer list

// capacity: empty, size, max_size
// Iterators: begin, end, cbegin, cend
// Element lookup: find, count, equal_range
// Modifiers: emplace, emplace_hint, insert, erase, clear, swap
// Buckets: bucket_count, max_bucket_count, bucket_size, bucket
// Hash policy: load_factor, max_load_factor, rehash, reserve
// Observers: hash_function, key_eq, get_allocator

int main() {
	
	unordered_set<int> s1 = {1,2,3,4,5,6,7};
    cout << "size: " << s1.size() << "\n" << "max_size: " << s1.max_size() << "\n";

    // find
    unordered_set<string> s2 = {"red", "green", "blue"};
    auto key = s2.find("green");
    if (key == s2.end()) {
        cout << "Not Found\n";
    } else {
        cout << *key << " Found\n";
    }

    // count

    for (int i = 5; i<10; ++i) {
        if (s1.count(i) == 0) {
            cout << i << " not an element\n";
        } else {
            cout << i << " an element\n"; 
        }
    }

    // equal_range

    unordered_set<int> sample;
    sample.insert({20, 30, 40});
    auto range = sample.equal_range(30);
    if (range.first != sample.end()) {
        for (; range.first != range.second; ++range.first) {
            cout << *range.first << '\n';
        }
    } else {
        cout << "Element is not there!!\n";
    }

    // emplace
    s2.clear();

    s2.emplace("Potatos");
    s2.emplace("milk");
    s2.emplace("flour");

    for (const string& x : s2) {
        cout << x << ' ';
    }
    cout << '\n';

    // emplace_hint
    s2.clear();
    s2.emplace_hint(s2.end(), "A");
    s2.emplace_hint(s2.end(), "B");
    s2.emplace_hint(s2.end(), "C");

    for (const string& x : s2) {
        cout << x << ' ';
    }
    cout << '\n';

    // insert, erase
    s2.clear();
    s2.insert({"A", "B", "C", "D"});
    s2.erase("C");
    for (const string& x : s2) {
        cout << x << ' ';
    }
    cout << '\n';

    // bucket_count: Returns the number of buckets in the unordered_set container
    unordered_set<string> s;
    s.clear();
    s.insert({"red", "green", "blue", "yellow", "purple", "pink"});
    unsigned n = s.bucket_count();
    cout << "The number of buckets: " << n << '\n';

    // max_bucket_count: Find the maximum number of buckets that unordered_set
    cout << "Maximum load factor: " << s.max_load_factor() << '\n';

    // bucket_size: which returns the total number of elements present in a specific bucket in an unordered_set container
    for (unsigned i=0; i<n; i++) {
        cout << i << " has " << s.bucket_size(i) << " elements\n";
    }

    // bucket:  which returns the bucket number of a specific element
    for (const string& x: s) {
        cout << x << " is in bucket #" << s.bucket(x) << endl;
    }

    // load_factor
    cout << "Load_factor: " << s.load_factor() << endl;

    // max_load_factor
    cout << "max_load_factor: " << s.max_load_factor() << endl;

    // rehash: which sets the number of buckets in the container to N or more
    unordered_set<string> ss;

    ss.rehash(12);
    ss.insert({"h", "e", "l", "l", "o"});
    cout << "Current bucket: " << ss.bucket_count() << endl;

    // reserve: used to request capacity change of unordered_set.
    ss.reserve(5);
    cout << "Current bucket: " << ss.bucket_count() << endl;

    // hash_function: hash function is a unary function which takes a single argument only and
    // returns a unique value of type size_t based on it
    unordered_set<string> us;
    auto fn = us.hash_function();
    cout << "that: " << fn("that") << '\n' << "than: " << fn("than") << '\n';

    // key_eq: returns a boolean value according to the comparison
    unordered_set<string> us2;
    bool case1 = us2.key_eq()("checking", "CHECKING");
    case1 ? cout << "YES" : cout << "NO";
	return 0;
}