#include <bits/stdc++.h>
using namespace std;

vector<int> blocked, target;
unordered_map<int, pair<int, int>> adj;

int dist(int, int);

signed main(void) {
    int low, high, nb, nt;
    cin >> low >> high >> nb;
    blocked.assign(nb, 0);
    for (int& it : blocked)
    cin >> it;
    cin >> nt;
    target.assign(nt, 0);
    for (int& it : target) 
        cin >> it;
    for (int i = 0; i < nt; i++) {
        for (int j = 0; j < nt; j++) {
            adj[target[i]] = {target[j], dist(target[i], target[j])};
        }
    }
    exit(EXIT_SUCCESS);
}

int dist(int u, int v) {
    if (u == v) 
        return to_string(u).size();
    
}