#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solver(void);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

void solver(void) {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    ll s1 = 0, s2 = 0;
    for (auto& a : A) {
        cin >> a;
        s1 += a;
        s2 += (a + x - 1LL) / x; 
    }
    s1 = (s1 + x - 1LL) / x; 
    cout << s1 << " " << s2 << endl;
}
