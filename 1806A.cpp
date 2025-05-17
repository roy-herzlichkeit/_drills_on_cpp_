#include <bits/stdc++.h>
using namespace std;
	
void solver() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int y = d - b;
	if (y < 0) {
		cout << "-1\n";	
		return;
	}
	int N = y;
	a += y;
	int x = c - a;
	if (x > 0) {
		cout << "-1\n";
		return;
	}
	N += abs(x);
	cout << N << endl;
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
