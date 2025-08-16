#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string str = "...";
	if (s.find(str) != string::npos) {
		cout << 2 << endl;
	} else {
		int c = 0;
		for (int i = 0; i < n; i++)
			c += (s[i] == '.') ? 1 : 0;
		cout << c << endl;
	}
}
	
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
