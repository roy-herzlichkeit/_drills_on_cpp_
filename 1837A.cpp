#include <bits/stdc++.h>
using namespace std;

void solver() {
	int x, k;
	cin >> x >> k;
	if (x % k == 0) {
		cout << "2\n" << x - 1 << " " << 1 << endl;
	} else {
		cout << "1\n" << x << endl;
	}
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
