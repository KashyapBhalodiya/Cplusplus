#include <bits/stdc++.h>

using namespace std;

void isMajority(int arr[], int n) {
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < n; ++i) {
        arr[majorityIndex] == arr[i] ? count++ : count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }
    cout << arr[majorityIndex] << endl;
}

int main() {
    // Moore voting algorithm: Time: O(n) and space: O(1)
    // Find the majority element in the array

    int arr[] = {2, 2, 3, 2, 4, 2, 5};
    int n = sizeof(arr) / sizeof(int);
    isMajority(arr, n);
    return 0;
}
