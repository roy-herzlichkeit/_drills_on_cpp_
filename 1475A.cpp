#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solver() {
	ll n;
	cin >> n;
	if (n & (n - 1))
		cout << "YES\n";
	else
		cout << "NO\n";
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
