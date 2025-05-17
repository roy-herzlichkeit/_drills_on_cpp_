#include <bits/stdc++.h>
using namespace std;

void solver() {
        int a, b, x_k, y_k, x_q, y_q;
        cin >> a >> b >> x_k >> y_k >> x_q >> y_q;
        auto esValid = [&] (const int x, const int y) {
                if (x != x_q && y != y_q && x != x_k && y != y_k)
                        return true;
                else
                        return false;
        };
        auto hashPair = [] (const pair<int, int>& p) {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        };
        unordered_set<pair<int, int>, decltype(hashPair)> acceptables(8, hashPair);
        vector<pair<int, int>> pairs = {{a, b}, {-a, b}, {a, -b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
        for (const auto& p1 : pairs) {
                int a1 = p1.first, b1 = p1.second;
                int X1 = x_k + a1, Y1 = y_k + b1;
                for (const auto& p2 : pairs) {
                        int a2 = p2.first, b2 = p2.second;
                        int X2 = x_q + a2, Y2 = y_q + b2;
                        if (X1 == X2 && Y1 == Y2 && esValid(X1, Y1))
                                acceptables.insert({X1, Y1});
                }
        }
        cout << acceptables.size() << endl;
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