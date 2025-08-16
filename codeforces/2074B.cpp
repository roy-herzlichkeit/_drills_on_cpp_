#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> arr(n);
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (n == 1) {
		cout << arr[0] << endl;
		return;
	}
	sum += (1 - n);
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
