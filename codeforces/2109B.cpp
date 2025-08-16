#include <bits/stdc++.h>
using namespace std;

long long cutsForDimension(long long d, long long p) {
    if (d <= 1) return 0;
    if (d == 2) return 1;
    long long base = (long long)floor(log2(d));
    if ((d % 2 == 1) && (p == (d + 1) / 2) && (d > 2)) {
        base += 1;
    }
    return base;
}

void solver() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long rc = cutsForDimension(n, a);
    long long cc = cutsForDimension(m, b);
    cout << (rc + cc) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solver();
    return 0;
}