#include <bits/stdc++.h>
using namespace std;

void solver() {
	int a, b, n;
	cin >> a >> b >> n;
	vector<int> x(n);
	unsigned long long sum = b;
	for (int& it : x) {
		cin >> it;
		sum += min(a - 1, it);
	}
	cout << sum << endl;
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
	
