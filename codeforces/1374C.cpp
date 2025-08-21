#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

inline static void solver(void);

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<bool> stack;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack.push(true);
        } else {
            if (!stack.empty() && stack.top()) {
                stack.pop(); 
            } else {
                stack.push(false);
            }       
        }
    }
    int misplaced = 0;
    while (!stack.empty()) {
        misplaced += stack.top();
        stack.pop();
    }
    cout << misplaced << endl;
}