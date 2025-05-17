#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solver() {
	ll n;
	cin >> n;
	int res = 0;
	for (ll i = 1;;i++)
		if (n % i)
			break;
		else
			res++;
	cout << res << endl;
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
