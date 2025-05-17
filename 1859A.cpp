#include <bits/stdc++.h>
using namespace std;

void solver() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool flag_1 = false;
	int max = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
		if (a[i] == 1)
			flag_1 = true;
	}
	vector<int> b, c;
	if (flag_1) {	
		for (const auto& it : a) 
			if (it == 1)
				b.push_back(1);
			else
				c.push_back(it);
	} else {
		for (const auto& it : a)
			if (it == max)
				c.push_back(max);
			else
				b.push_back(it);
	}
	if (b.size() == 0 || c.size() == 0) {
		cout << -1 << endl;
		return;
	}
	cout << b.size() << " " << c.size() << endl;
	for (const auto& it : b)
		cout << it << " ";
	cout << endl;
	for (const auto& it : c)
		cout << it << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
