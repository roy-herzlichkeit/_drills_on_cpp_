#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n, a, b;
	cin >> n >> a >> b;
	bool flag = false;
	if ((a == n && b == n) || (a + b + 1) < n)
		flag = true;
	cout << (flag? "Yes" : "No") << "\n";
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
