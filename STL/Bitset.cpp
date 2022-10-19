#include <bits/stdc++.h>
using namespace std;

int main() {

	bitset<4> a; // 0000
    a.set(); // 1111

    // to_string

    string s = a.to_string();

    cout << s << '\n';

    cout << a.to_ulong() << '\n'; // 1111 = 15 <= binary number system
    cout << a.to_ullong() << '\n';
	return 0;
}