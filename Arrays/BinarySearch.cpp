#include <bits/stdc++.h>

using namespace std;

int binarySearchRecursive(int a[], int l, int r, int key) {
    if (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) {
            return m;
        }

        // if element is smaller then mid then it will present left subarray
        if (a[m] > key) {
            return binarySearchRecursive(a, l, m - 1, key);
        }

        // otherwise the element present right subarray
        return binarySearchRecursive(a, m+1, r, key);
    }
    return -1;
}

int binarySearch(int a[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) {
            return m;
        }

        if (a[m] < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {2, 3, 4, 10, 12, 40};
    int key = 12;
    int n = sizeof(a) / sizeof(int);
    int result = binarySearch(a, 0, n-1, key);
    (result == -1) ? cout << "Element is not present" : cout << "Element is present at index: " << result << endl;

    // recursive binary search
    int result2 = binarySearchRecursive(a, 0, n-1, key);
    (result2 == -1) ? cout << "Element is not present" : cout << "Element is present at index: " << result2 << endl;
    return 0;
}
