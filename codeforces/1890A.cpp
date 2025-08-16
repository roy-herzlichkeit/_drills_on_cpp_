#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		unordered_map<int, int> map;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			map[arr[i]]++;
		}
		if (map.size() > 2) {
			cout << "NO\n";
			continue;
		}
		vector<int> count(2, 0);
		int i = 0;
		for (const auto& it : map)
			count[i++] = it.second;
		if (n % 2 == 1 && (count[0] + 1 == count[1] || count[1] + 1 == count[0]))
			cout << "YES\n";
		else if (count[0] == count[1])
			cout << "YES\n";
		else if (count[0] == n || count[1] == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
		
				
