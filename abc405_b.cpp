#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> map(M, 0), A(N, 0);
    for (auto& it : A) {
        cin >> it;
        map[it - 1]++;
    }
    for (const auto& it : map) {
        if (it == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    int n = N;
    while (N > 0) {
        if (A[N - 1] <= M) {
            int temp = --map[A[N - 1] - 1];
            if (temp == 0)
                break;
        }
        N--;
    }
    cout << (n - N + 1) << endl;
    return 0;
}