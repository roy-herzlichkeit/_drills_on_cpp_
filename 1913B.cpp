#include <bits/stdc++.h>
using namespace std;

inline static void solver(void) {
    string s;
    cin >> s;
    vector<int> count(2, 0);
    for (char& c : s)
        count[c - '0']++;
    if (count[0] != count[1]) {
        for (char& c : s) {
            if (c == '0') {
                if (count[1] == 0)
                    break;
                count[1]--;
            } else {
                if (count[0] == 0)
                    break;
                count[0]--;
            }
        }
        cout << (count[1] + count[0]) << endl;
    } else {
        cout << "0\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}