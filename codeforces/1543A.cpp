#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	auto func = [&] (ll& a, ll& b) {
		ll X = abs(a - b);
		ll m = a % X;
		m = min(X - m, m);
		cout << X << " " << m << "\n";
	};
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0 0\n";
		} else {
			func(a, b);
		}		
	}
	return 0;
}
