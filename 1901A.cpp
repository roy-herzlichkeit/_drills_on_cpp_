#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> d(n + 1, 0);
	d[0] = a[0];
	for (int i = 1; i < n; i++)
		d[i] = a[i] - a[i - 1];
	d[n] = 2 * (x - a[n - 1]);
	cout << *max_element(d.begin(), d.end()) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
