#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	string s;
	cin >> n >> s;
	if (n == 1) {
		cout << "2\n";
		return;
	}
	int res = 0, i = 0;
	while (i < n) {
		char curr = s[i];
		int c = 0;
		while (i < n && s[i] == curr) {
			c++;
			i++;
		}
		res = max(res, c);
	}
	cout << res + 1 << endl;
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
