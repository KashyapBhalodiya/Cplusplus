#include <bits/stdc++.h>

using namespace std;

/*
Working of Algorithm :

- Find minimum and maximum values in array. Let the minimum and maximum values be ‘min’ and ‘max’ respectively.
Also find range as ‘max-min+1’.
- Set up an array of initially empty “pigeonholes” the same size as of the range.
- Visit each element of the array and then put each element in its pigeonhole. An element arr[i] is put in hole at index arr[i] – min.
- Start the loop all over the pigeonhole array in order and put the elements from non- empty holes back into the original array.

*/

void pigeonholeSort(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1; // Find range

    // Create an array of vectors. Size of array range. Each vector represents a hole that is going to contain matching elements.
    vector<int> holes[range];

    // Traverse through input array and put every element in its respective hole
    for (int i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);

    // Traverse through all holes one by one. For every hole, take its elements and put in array.
    int index = 0;
    for (int i = 0; i < range; i++)
    {
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++]  = *it;
    }
}

int main() {
    // pigeon hole principal: Time: O(n + range) and space: O(1)
    int arr[] = {8, 3, 2, 7, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    pigeonholeSort(arr, n);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
