#include <bits/stdc++.h>
using namespace std;

int cutsForDimension(long long d, long long pos) {
    // Base cuts = floor(log2(d))
    int baseCuts = (int)floor(log2(d));

    // Check if d is odd (> 2) and pos is the unique middle cell
    // For example, d=7 => middle=4
    // If in that exact cell, Fouad can force one more cut
    if (d > 2 && (d % 2 == 1) && (pos == (d + 1) / 2)) {
        baseCuts += 1;
    }
    return baseCuts;
}

void solver() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    // Calculate row-cuts + column-cuts
    int rowCuts = cutsForDimension(n, a);
    int colCuts = cutsForDimension(m, b);

    cout << (rowCuts + colCuts) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solver();
    return 0;
}