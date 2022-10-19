#include <bits/stdc++.h>
using namespace std;

/*
Prefix array:
There is a simple yet powerful technique that allows for the fast calculation of sums of elements in given slice.

Given an array arr[] of size n, its prefix sum array is another array prefixSum[] of the same size, such that
the value of prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i].

Input: {10, 20, 10, 5, 15}

Output: {10, 30, 40, 45, 60}

*/

void helper(int* a, int n, int* prefixSum) {
    prefixSum[0] = a[0];

    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
}

int main() {
    int a[] = {10, 20, 10, 5, 15};
    int n = sizeof(a) / sizeof(int);

    int prefixSum[n];

    helper(a, n, prefixSum);
    cout << "Prefix Sum: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << prefixSum[i] << " ";
    }
    return 0;
}
