#include <bits/stdc++.h>

using namespace std;

int search(int* arr, int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void search2(vector<int> a, int key) {
    int left = 0, length = a.size(), position = -1, right = length - 1;

    for (left = 0; left <= right;) {
        // if search variable found the left side
        if (a[left] == key) {
            position = left;
            cout << "Element found at index: " << position << " position with " << left + 1 << " attempt";
            break;
        }

        // if search variable found the right side
        if (a[right] == key) {
            position = right;
            cout << "Element found at index: " << position << " position with " << length - right << " attempt";
        }
        left++;
        right--;
    }

    // If element not found
    if (position == -1) {
        cout << "The element is not found" << endl;
    }
}

int main() {
    int arr[] = {2, 4, 6, 7, 10, 12, 18};
    int key = 12;
    int n = sizeof(arr) / sizeof(arr[0]);

    int linearSearch = search(arr, n, key);
    (linearSearch == -1) ? cout << "Element is not present in the array" : cout << "Element is present at index: " << linearSearch << endl;

    // improve the linear search
    vector<int> a{2, 4, 6, 7, 10, 12, 18};
    search2(a, key);
    return 0;
}
