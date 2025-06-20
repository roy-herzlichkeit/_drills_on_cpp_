#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (const int& num : nums) {
            if (set.find(num) != set.end())
                return true;
            set.insert(num);
        }
        return false;
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
    cout << object.containsDuplicate(nums) << endl;
    exit(EXIT_SUCCESS);
}