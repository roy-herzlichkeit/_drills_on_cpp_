#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	int minima = INT_MAX;
	while (n--) {
		int temp;
		cin >> temp;
		minima = min(minima, abs(temp));
	}
	cout << minima << endl;
}

int main() {
	solver();
	return 0;
}
