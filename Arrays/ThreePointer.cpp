#include <bits/stdc++.h>

using namespace std;

bool naive(int A[], int n, int sum) {
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (A[i] + A[j] + A[k] == sum)
                {
                    cout << A[i] << " " << A[j] << " " << A[k] << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool optimal(int A[], int n, int sum) {
    int l, r;
    sort(A, A + n);

    for (int i = 0; i < n - 2; i++) {
        l = i + 1;
        r = n - 1;
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("%d %d %d\n", A[i], A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else
                r--;
        }
    }
    return false;
}

bool hashApproach(int A[], int n, int sum) {
    for (int i = 0; i < n - 2; i++)
    {
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("%d %d %d\n", A[i],A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
    return false;
}

int main() {
// Naïve approach Time: O (n3) Space: O (1)
// Optimal approach Time: O (n2) Space: O (1)
// Hashing based approach Time: O (n2) Space: O (n)

    int a[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int n = sizeof(a) / sizeof(int);
    naive(a, n, sum);
    optimal(a, n, sum);
    hashApproach(a, n, sum);
    return 0;
}
