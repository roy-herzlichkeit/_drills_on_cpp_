#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == b && c == d && a == c && d == a)
			cout << "YES\n";
		else
			cout << "NO\n"; 
	}
	return 0;
}
