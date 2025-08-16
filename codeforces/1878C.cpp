#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void solver() {
	ll n, k, x;
	cin >> n >> k >> x;
	auto Sum = [&k] (ll a) {
		return (k * (2 * a + k - 1)) / 2;
	};	
	ll low = Sum(1), high = Sum(n - k + 1);
	if (low <= x && x <= high) 
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
