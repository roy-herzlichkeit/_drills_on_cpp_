#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n;
    cin >> n;
    int temp;
    cin >> temp;
    int EXOR = temp;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        EXOR ^= temp;
    }
    if (n % 2 == 0) 
        cout << (EXOR == 0 ? "0" : "-1") << "\n";
    else 
        cout << EXOR << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    return 0;
}
