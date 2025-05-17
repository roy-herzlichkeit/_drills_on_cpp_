#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		cin >> a[0];
		for (int i = 1; i < n; i++)
			cin >> a[i];
		if (a[0] != 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
