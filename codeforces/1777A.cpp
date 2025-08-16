#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] % 2 == arr[i + 1] % 2)
            res++;
    }
    cout << res << "\n";
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
