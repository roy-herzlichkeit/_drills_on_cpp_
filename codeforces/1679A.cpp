#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n % 2 || n == 2) {
			cout << -1 << endl;
			continue;
		}
		n = n >> 1;
		ll a = (n + 2) / 3;
		n = n >> 1;
		cout << a << " " << n << endl;
	}
	return 0;
}
			
		
