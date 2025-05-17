#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(int arr[], int n) {
    int g = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g = min(__gcd(arr[i], arr[j]), g);
        }
    }
    return g <= 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << (isBeautiful(arr, n) ? "YES\n" : "NO\n");
    }
}
