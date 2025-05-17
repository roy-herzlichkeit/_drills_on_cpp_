#include <bits/stdc++.h>
using namespace std;

inline static void solver(void);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    return 0;
}

inline static void solver(void) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i] = abs(A[i]);
    }
    int x = A[0];
    sort(A.begin(), A.end());
    auto it = find(A.begin(), A.end(), x);
    int idx = distance(A.begin(), it);
    int med = n / 2;
    if (idx <= med) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}