#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (map.find(target - nums[i]) != map.end()) 
                return {map[target - nums[i]], i};
            map[nums[i]] = i;
        }
        return {0, 0};
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;
    cin >> n;
    vector<int> res = object.twoSum(nums, n);
    cout << res[0] << " " << res[1] << endl;
    exit(EXIT_SUCCESS);
}