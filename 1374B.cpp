#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	int drei = 0, zwei = 0;
	while (n % 3 == 0) {
		drei++;
		n /= 3;
	}
	while (n % 2 == 0) {
		zwei++;
		n /= 2;
	}
	if (n > 1) 
		cout << -1 << endl;
	else if (zwei > drei)
		cout << -1 << endl;
	else
		cout << (drei + (drei - zwei)) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
