#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int& it : arr)
		cin >> it;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	sort(arr.begin(), arr.end());
	int res = 0, curr = 0;
	for (int i = 0; i < n - 1; i++) {
		if ((arr[i + 1] - arr[i]) > k) {
			res = max(res, curr + 1);
			curr = 0;
		} else {
			curr++;
		}
	}
	res = max(res, curr + 1);
	cout << (n - res) << endl;
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
			 
