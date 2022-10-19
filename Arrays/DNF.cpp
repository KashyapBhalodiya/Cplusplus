#include <bits/stdc++.h>

using namespace std;

void DNF(int arr[], int n) {
    int low = 0, high = n - 1, mid = 0;
    while (mid <= high) {
        switch(arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // DNF: Dutch national flag algorithm for sort the array
    // Time: O (n) and space: O (1)
    int arr[] = {0,0,1,2,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    DNF(arr, n);
    return 0;
}
