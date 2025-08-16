#include <bits/stdc++.h>
using namespace std;

inline static int getDistance(int, int, int, int);
inline static void solver(void);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    return 0;
}

inline static int getDistance(int a, int b, int x, int y) {
    return abs(y - b) + abs(x - a);
}

inline static void solver(void) {
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    vector<pair<int, int>> endpoints = {{1, 1}, {1, m}, {n, 1}, {n, m}};
    auto cord = [] (vector<pair<int, int>> endpoints, int i, int j) {
        pair<int, int> res;
        int max = -1;
        for (const auto& endpoint : endpoints) {
            int x = endpoint.first, y = endpoint.second, dist = getDistance(x, y, i, j);
            if (dist > max) {
                max = dist;
                res = endpoint;
            }
        }
        return res;
    };
    pair<int, int> cord1 = cord(endpoints, i, j), cord2 = cord(endpoints, cord1.first, cord1.second);
    cout << cord1.first << " " << cord1.second << " " << cord2.first << " " << cord2.second << "\n"; 
}