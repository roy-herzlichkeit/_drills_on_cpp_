#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int temp;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (temp == k)
				flag = true;
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
