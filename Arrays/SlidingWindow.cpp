#include <bits/stdc++.h>

using namespace std;

int slidingWindow(int arr[], int k, int n, int& start, int& end) {
    if (k > n)
        return -1;

    int maxSum = 0, currSum = 0;
    for (int i = 0; i < k; ++i) {
        currSum += arr[i];
    }

    maxSum = currSum;
    start = 0;
    end = k - 1;
    // Sliding the window and updating maximumSum
    for (int i = k; i < n; i++)
    {
        // Add the rightmost element to the window and discard the leftmost element from the window
        currSum += arr[i] - arr[i-k];
        if (currSum > maxSum)
        {
            maxSum = currSum;
            start = i - k + 1; // the window starts one ahead of the element that was removed from the left
            end = i; // the window goes upto the position of the newly added element from the right
        }
    }
    return maxSum;
}

int main() {
    // Sliding window Time: O(n) and space: O(1)
    int arr[] = {6, 2, -1, 9, 1, -2};
    int k = 3;
    int n = sizeof(arr) / sizeof(int);
    int start = 0, end = 0;
    int maxSum = slidingWindow(arr, k, n, start, end);
    cout << "The maximum sum is: " << maxSum;
    cout << " from position " << start << " till " << end << endl;
    return 0;
}
