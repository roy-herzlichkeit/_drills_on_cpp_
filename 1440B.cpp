#include <bits/stdc++.h>
using namespace std;

void solver(void);

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

void solver(void) {
    int n, k;
    cin >> n >> k;
    int N = n * k;
    vector<int> A(N);
    for (auto& a : A)
        cin >> a;
    int c = (n + 1)/ 2 + (n % 2 == 0 ? 1 : 0), i = N - c;
    long long S = 1LL * 0;
    while (k--) {
        S += 1LL * A[i];
        i -= c;
    }
    cout << S << endl;
}