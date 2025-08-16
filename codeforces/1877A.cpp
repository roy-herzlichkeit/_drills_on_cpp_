#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		for (int temp, i = 0; i < n - 1; i++) {
			cin >> temp;
			sum += temp;
		}
		sum *= -1;
		cout << sum << endl;
	}
	return 0;
}
