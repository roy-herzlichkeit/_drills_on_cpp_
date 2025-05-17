#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	bool flag = true;
	for (int temp, i = 0; i < n; i++) {
		cin >> temp;
		if (temp % 2)
			flag = !flag;
	}
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
