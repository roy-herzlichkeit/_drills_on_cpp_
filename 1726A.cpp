#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> mainak(n);
	for (int& it : mainak) 
		cin >> it;
	int value = 0;
	for (int i = 0; i < n; i++) {
		value = max(value, mainak[i] - mainak[0]);
		value = max(value, mainak[n - 1] - mainak[i]);
		value = max(value, mainak[(n + i - 1) % n] - mainak[i]); 
	}
	cout << value << endl;
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
