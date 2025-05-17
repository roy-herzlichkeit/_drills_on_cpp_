#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n, k, x;
	cin >> n >> k >> x;
	if (x != 1) {
		cout << "YES\n";
		cout << n << endl;
		while (n--)
			cout << 1 << " ";
		cout << endl;
		return;
	}
	else {
		if ((k <= 2 && n % 2) || k == 1) {
			cout << "NO\n";
			return;
		}
		if (n % 2 == 1) {
			cout << "YES\n";
			int S;
			if (k % 2 == 0)
				k--;	
			S = 1 + (n - k + 1) / 2;
			cout << S << endl;
			S--;
			while (S--)
				cout << 2 << " ";
			cout << k << endl;
		} else {
			n /= 2;
			cout << "YES\n" << n << endl;
			while (n--)
				cout << 2 << " ";
			cout << endl;
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) 
		solver();
	return 0;
}
