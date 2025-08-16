#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left] == s[right]) {
			break;
		} 
		left++;
		right--;
	}
	cout << (right - left + 1) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
