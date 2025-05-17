#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int diff = INT_MAX;
	cin >> arr[0];
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		diff = min(diff, arr[i] - arr[i - 1]);
	}
	if (diff < 0) {
		cout << 0 << endl;
		return;
	}
	diff = (diff / 2) + 1;
	cout << diff << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
