#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void solver(void) {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> peasants(n);
    for (auto& peasant : peasants) 
        cin >> peasant.first;
    for (auto& peasant : peasants) 
        cin >> peasant.second;
    sort(peasants.begin(), peasants.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    });
    ll cost = p;
    int rem = n - 1;
    for (int i = 0, j = n - 1; rem > 0 && i < n; i++) {
        if (peasants[i].second >= p)
            break;
        int k = peasants[i].first;
        while (rem > 0 && k--) {
            j--;
            rem--;
            cost += peasants[i].second;
        }
    }
    cost += (rem <= 0) ? 0 : (1LL * p * (1LL * rem));
    cout << cost << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}