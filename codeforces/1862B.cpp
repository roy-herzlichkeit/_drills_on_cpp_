#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (n == 1) {
		cout << 1 << endl << b[0] << endl;
		return;
	}
	vector<int> a;
	a.push_back(b[0]);
	for (int i = 1; i < n; i++) {
		if (b[i - 1] <= b[i]) {
			a.push_back(b[i]);
		} else {
			a.push_back(b[i]);
			a.push_back(b[i]);
		}
	}
	n = a.size();
	cout << n << endl;
	for (const auto& it : a)
		cout << it << ' ';
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}

