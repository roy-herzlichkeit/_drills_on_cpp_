#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (const int& num : nums) {
            map[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (const auto& [x, y] : map)
            pq.push({y, x});
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
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