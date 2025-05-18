#include <bits/stdc++.h>
using namespace std;

void solver(void) {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& a : A)
        cin >> a;
    priority_queue<int, vector<int>, greater<int>> pq;
    if (k == 4) {
        priority_queue<int, vector<int>, greater<int>> pq2;
        int x, x2;
        for (const auto& a : A) {
            x = a % 4;
            x2 = a % 2;
            if (x == 0) {
                cout << "0\n";
                return;
            }
            pq2.push(x2);
            pq.push(4 - x);
        }
        int m1 = pq.top();
        int m2 = pq2.top();
        pq2.pop();
        m2 += pq2.top();
        cout << min(m1, m2) << endl;
    } else {
        int x;
        for (const auto& a : A) {
            x = a % k;
            if (x == 0) {
                cout << "0\n";
                return;
            }
            pq.push(k - x);
        }
        int m = pq.top();
        cout << m << endl;
    }
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