#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n, k = 0;
	cin >> n;
	auto count_digits = [] (int n) {
		int k = 0;
		while (n > 0) {
			k++;
			n /= 10;
		}
		return k - 1;
	};
	k = count_digits(n);
	cout << (int(n / pow(10, k)) + k * 9) << endl;
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
