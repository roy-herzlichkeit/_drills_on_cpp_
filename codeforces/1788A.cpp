#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n, count = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		count += (arr[i] == 2);
	}
	if (count % 2 == 1) {
		cout << "-1\n";
		return;
	} else if (count == 0) {
		cout << "1\n";
		return;
	}
	for (int i = 0, curr = 0; i < n; i++) {
		curr += (arr[i] == 2);
		if ((count - curr) == curr) {
			cout << (i + 1) << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solver();
	return 0;
}
