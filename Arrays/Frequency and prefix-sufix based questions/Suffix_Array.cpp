#include <bits/stdc++.h>
using namespace std;

/*
Suffix array:
A suffix array is a sorted array of all suffixes of a string.

A suffix array will contain integers that represent the starting indexes of the all the suffixes of a given string,
after the aforementioned suffixes are sorted.

As an example look at the string s = abaab. All the suffixes are as follows:
0. abaab
1. baab
2. aab
3. ab
4. b

After sorting these strings:
2. aab
3. ab
0. abaab
4. b
1. baab

Brute force:
Sort the array using quicksort or mergesort and comparing the elements its additionally it will take O(n^2 logn)

*/

int main() {
    string s = "abaab";
    int n = s.length();
    map<string, int> Map;
    int suffix[n];

    // mapping index
    string sub = "";
    for (int i = n - 1; i >= 0; --i) {
        sub = s[i] + sub;
        Map[sub] = i;
    }

    int j = 0;
    for (auto x : Map) {
        suffix[j] = x.second;
        j++;
    }

    cout << "Suffix array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << suffix[i] << ' ';
    }
    cout << endl;
    return 0;
}
