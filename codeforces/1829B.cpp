#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> ids;
	ids.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i])
			ids.push_back(i);
	}
	ids.push_back(n);
	int maximus = ids[1];
	for (int i = 1, m = ids.size(); i < m - 1; i++) {
		maximus = max(maximus, ids[i + 1] - ids[i] - 1);
	}
	cout << maximus << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solver();
	}
	return 0;
}
