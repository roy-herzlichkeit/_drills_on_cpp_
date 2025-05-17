#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string x, s;
		cin >> x >> s;
		vector<string> list(6, x);
		for (int i = 1; i < 6; i++)
			list[i] = list[i - 1] + list[i - 1];
		bool flag = true;
		for (int i = 0; i < 6; i++) {
			if (list[i].find(s) != string::npos) {
				cout << i << endl;
				flag = false;
				break;
			}
		}
		if (flag) 
			cout << -1 << endl;
	}
}
