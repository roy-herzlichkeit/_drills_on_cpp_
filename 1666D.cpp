#include <bits/stdc++.h>
using namespace std;

inline static void solver(void);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solver();
    }
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    string s, t, r = "";
    cin >> s >> t;
    if (s == t) {
        cout << "YES\n";
        return;
    }
    vector<vector<int>> Smap(26);
    vector<int> Tmap(26, 0);
    int k = 0;
    for (const char& c : s) {
        Smap[c - 'A'].push_back(k++);
    }
    for (const char& c : t) {
        k = c - 'A';
        Tmap[k]++;
        if (Smap[k].empty() || Tmap[k] > Smap[k].size()) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> indices;
    for (int i = 0, n = Tmap.size(); i < n; i++) {
        if (Tmap[i] == 0)
            continue;
        indices.insert(indices.end(), Smap[i].end() - Tmap[i], Smap[i].end());
    }
    sort(indices.begin(), indices.end());
    for (const auto& id : indices) {
        r += s[id];
    }
    if (r == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}