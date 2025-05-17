#include <iostream>
using namespace std;

void solver() {
    int n;
    cin >> n;
    int prev, cur;
    cin >> cur;
    if (cur == 1)
        cur = 2;
    cout << cur << " ";
    prev = cur;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        if (cur == 1)
            cur = 2;
        if (cur % prev == 0)
            cur++;
        cout << cur << " ";
        prev = cur;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    return 0;
}
