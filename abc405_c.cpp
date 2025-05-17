#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<ll> S(N - 1, 0);
    for (auto& a : A)
        cin >> a;
    S[0] = A[0];
    for (int i = 1; i < N - 1; i++) 
        S[i] = S[i - 1] + A[i];
    ll V = 0;
    for (int i = N - 1; i > 0; i--) 
        V += S[i - 1] * A[i];
    cout << V << endl;
    return 0;
}