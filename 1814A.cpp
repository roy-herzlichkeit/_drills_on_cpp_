#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll gcd(const ll& a, const ll& b) {
	return b == 0 ? a : gcd(b, a % b);	
}

void solver() {
	ll n, k;
	cin >> n >> k;
	ll x = gcd(2, k);
	if (!(n % x))
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
