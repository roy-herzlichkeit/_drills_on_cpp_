#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const string& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto& [x, y] : map)
            res.push_back(y);
        return res;
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
    exit(EXIT_SUCCESS);
}