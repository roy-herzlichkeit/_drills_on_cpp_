#include <bits/stdc++.h>
using namespace std;

inline static void solver(void);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solver();
    }
    return 0;
}

inline static void solver(void) {
    string s;
    cin >> s;
    short n = s.size();
    if (s[0] != s[n - 1])
        s[0] = s[n - 1];
    cout << s << endl;
}