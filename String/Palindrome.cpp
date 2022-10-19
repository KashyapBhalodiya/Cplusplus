#include <bits/stdc++.h>

using namespace std;

string isPalindrome(string s) {
    string p = s;
    reverse(s.begin(), s.end());

    if (s == p)
        return "YES";
    else
        return "NO";
}

// string isPalindrome(string S)
// {
//     for (int i = 0; i < S.length() / 2; i++) {
//         if (S[i] != S[S.length() - i - 1]) {
//             return "No";
//         }
//     }
//     return "Yes";
// }

int main() {
    // String is palindrome or not

    string s = "ABCBA";
    cout << isPalindrome(s);
    return 0;
}
