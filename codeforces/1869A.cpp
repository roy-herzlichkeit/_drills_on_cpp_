#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
		cin >> temp;
	if (n ) {
		cout << "2\n1 " << n << "\n1 " << n << endl;
		return;
	}
	cout << 4 << endl;
	cout << 1 << " " << n - 1 << endl;	
	cout << 1 << " " << n - 1 << endl;
	cout << n - 1 << " " << n << endl;
	cout << n - 1 << " " << n << endl;	
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
