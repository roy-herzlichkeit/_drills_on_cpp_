#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static inline unsigned long long splitmix64(unsigned long long x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

static mt19937_64 rng((unsigned)splitmix64(chrono::high_resolution_clock::now().time_since_epoch().count()));

struct chash {
    size_t operator()(unsigned long long x) const {
        static const unsigned long long FIXED_RANDOM = splitmix64(chrono::high_resolution_clock::now().time_since_epoch().count());
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};

#ifndef ONLINE_JUDGE
  #define dbg(...) do{ fprintf(stderr, "DBG (%s:%d) = ", __FILE__, __LINE__); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); } while(0)
  #define debug_var(x) cerr << #x << " = " << (x) << "\n";
#else
  #define dbg(...) (void)0
  #define debug_var(x) (void)0
#endif

template<class T> inline T aabs(T x){ return x < 0 ? -x : x; }
template<class T> inline T ceil_div(T a, T b){ return (a + b - 1) / b; }
template<class T> inline void chmin(T &a, T b){ if(b < a) a = b; }
template<class T> inline void chmax(T &a, T b){ if(b > a) a = b; }

inline static void solver() {
    int H, W;
    cin >> H >> W;
    
    vector<string> grid(H);
    for (int i = 0; i < H; i++) 
        cin >> grid[i];
    
    int start_r = -1, start_c = -1, goal_r = -1, goal_c = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'G') {
                goal_r = i;
                goal_c = j;
            }
        }
    }
    
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(2, -1)));
    queue<tuple<int, int, int>> q; 
    
    q.push({start_r, start_c, 0});
    dist[start_r][start_c][0] = 0;
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int r = get<0>(curr);
        int c = get<1>(curr);
        int door_state = get<2>(curr);
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) 
                continue;
            
            char cell = grid[nr][nc];
            
            if (cell == '#') continue;
            
            if (cell == 'o' || cell == 'x') {
                bool is_open = (door_state == 0) ? (cell == 'o') : (cell == 'x');
                if (!is_open) 
                    continue;
            }
            
            int new_door_state = door_state;
            if (cell == '?') {
                new_door_state = 1 - door_state;
            }
            
            if (dist[nr][nc][new_door_state] == -1) {
                dist[nr][nc][new_door_state] = dist[r][c][door_state] + 1;
                q.push({nr, nc, new_door_state});
            }
        }
    }
    
    int ans = -1;
    if (dist[goal_r][goal_c][0] != -1) {
        ans = dist[goal_r][goal_c][0];
    }
    if (dist[goal_r][goal_c][1] != -1) {
        if (ans == -1 || dist[goal_r][goal_c][1] < ans) {
            ans = dist[goal_r][goal_c][1];
        }
    }
    
    cout << ans << "\n";
}

int main() {
    fast_io();
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif

    solver();

    return 0;
}