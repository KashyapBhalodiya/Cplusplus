#include <bits/stdc++.h>
using namespace std;

/*
We are given an array of integer elements which contains duplicate values and the task is to calculate
the frequencies of the distinct elements present in an array and print the result.
Input:
arr[] = {1, 1, 2, 3, 4, 1, 2, 3}

Output:
frequency of 1 is: 3
frequency of 2 is: 2
frequency of 3 is: 2
Frequency of 4 is: 1

*/

void frequency(int* arr, int n) {
    bool check[n];
    for (int i = 0; i < n; ++i) {
        check[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        if (check[i] == 1)
            continue;
        int count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                check[j] = 1;
                count++;
            }
        }
        cout << "Frequency of " << arr[i] << " is: " << count << endl;
    }
}

int main() {
    int arr[] = {1, 1, 2, 3, 4, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    frequency(arr, n);
    return 0;
}
