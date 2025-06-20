#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> map(26, 0);
        for (int i = 0, n = s.size(); i < n; i++) {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for (const int& it : map) 
            if (it)
                return false;
        return true;
    }
};

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif
    Solution object;
    string s, t;
    cin >> s >> t;
    cout << object.isAnagram(s, t) << endl;
    exit(EXIT_SUCCESS);
}