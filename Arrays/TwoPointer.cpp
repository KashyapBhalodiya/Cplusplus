#include <bits/stdc++.h>

using namespace std;

bool naive(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;

            if (arr[i] + arr[j] == key) {
                return true;
            }

            if (arr[i] + arr[j] > key) {
                break;
            }
        }
    }
    return false;
}

bool optimal(int arr[], int n, int key) {
    int i = 0, j = n - 1; // make the first and last pointer
    while (i < j) {
        if (arr[i] + arr[j] == key) {
            return 1;
        } else if (arr[i] + arr[j] < key) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}

int main() {
    int arr[] = {2, 3, 5, 8, 10, 11};
    int key = 10;
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n);

    // naiver approach or brute force approach. Time = O (n2)
    cout << naive(arr, n, key) << endl;

    // Optimal approach. Time = O(n)
    cout << optimal(arr, n, key) << endl;

    return 0;
}
