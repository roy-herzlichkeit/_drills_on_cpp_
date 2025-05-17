#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    ll T = 1;
    for (int i = 0; i < K; i++) 
        T *= 10;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) 
        cin >> A[i];
    ll S = 1;
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        if (S > (T - 1) / a) {
            S = 1;
        } else {
            ll Q = S * a;
            if (Q >= T) {
                S = 1;
            } else {
                S = Q;
            }
        }
    }
    cout << S << endl;
    
    return 0;
}