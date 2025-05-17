#include <bits/stdc++.h>
using namespace std;

void solver(void);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}

void solver(void) {
	int n;
	cin >> n;
	unordered_map<int, int> map;
	for (int temp, i = 0; i < n; i++) {
		cin >> temp;
		map[temp]++;
	}
	int H = 0, O = 0;
	for (const auto& it : map) {
		H = max(it.second, H);
	}
	while (H <= n - H) {
		O += 1 + H;
		H *= 2;
	}
	if (H != n)
		O += 1 + n - H;
	cout << O << endl;
}
