#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int H, W;
    cin >> H >> W;
    vector<vector<char>> GRID(H, vector<char>(W, '#'));
    vector<vector<int>> DIST(H, vector<int>(W, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> GRID[i][j];
            if (GRID[i][j] == 'E') {
                DIST[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto id = q.front();
        q.pop();
        int i = id.first, j = id.second;
        for (auto& move : moves) {
            int ix = move.first, iy = move.second;
            int x = i + ix, y = j + iy;
            if (x < 0 || x >= H || y < 0 || y >= W)
                continue;
            char ch = GRID[x][y];
            if (ch == '#' || ch == 'E')
                continue;
            if (DIST[x][y] < DIST[i][j] + 1)
                continue;
            DIST[x][y] = DIST[i][j] + 1;
            if (ix == -1) {
                GRID[x][y] = 'v';
            } else if (ix == 1) {
                GRID[x][y] = '^';
            } else if (iy == -1) {
                GRID[x][y] = '>';
            } else {
                GRID[x][y] = '<';
            }
            q.push({x, y});
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << GRID[i][j];
        }
        cout << "\n";
    }
    return 0;
}