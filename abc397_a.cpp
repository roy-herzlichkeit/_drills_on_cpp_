#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double X;
    cin >> X;
    if (X >= 38.00)
        cout << "1\n";
    else if (X >= 37.5)
        cout << "2\n";
    else    
        cout << "3\n";
    return 0;
}