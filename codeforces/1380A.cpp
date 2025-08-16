#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& it : arr)
        cin >> it;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) {
            cout << "YES\n" << i << " " << (i + 1) << " " << (i + 2) << "\n";
            return;
        }
    }
    cout << "NO\n";
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