#include <bits/stdc++.h>
using namespace std;

void solver() {
    string s;
    cin >> s;
    int temp = static_cast<int>(count(s.begin(), s.end(), '0'));
    cout << (min(temp , int(s.size()) - temp) % 2 ? "DA" : "NET") << "\n";
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
