#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A < C) {
        cout << "No\n";
    } else if (A == C) {
        if (B < D)
            cout << "No\n";
        else    
            cout << "Yes\n";
    } else {
        cout << "Yes\n";
    }
    exit(EXIT_SUCCESS);
}