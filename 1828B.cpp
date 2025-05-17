#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = abs(arr[i] - (i + 1));
	}
	int gcd = arr[0];
	for (int i = 1; i < n; i++)
		gcd = __gcd(arr[i], gcd);
	cout << gcd << endl;
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
