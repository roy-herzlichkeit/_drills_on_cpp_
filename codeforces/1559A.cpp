#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solver() {
    int n;
    cin >> n;
    int res;
    for (int i = 0, temp; i< n; i++) {
        cin >> temp;
        res = (i == 0) ? temp : res & temp;
    }
    cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
        solver();
	}
	return 0;
}
