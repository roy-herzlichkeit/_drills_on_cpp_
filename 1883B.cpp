#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;
	n = 0;
	for (const auto& it : freq)
		n += it.second % 2;
	n--;
	cout << ((n <= k) ? "YES\n" : "NO\n");
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