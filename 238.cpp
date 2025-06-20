#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) 
            res[i] = nums[i - 1] * res[i - 1];
        for (int i = n - 2, product = nums[n - 1]; i >= 0; product *= nums[i], i--) 
            res[i] *= product;
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