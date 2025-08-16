#include <bits/stdc++.h>
using namespace std;

void solver() {
    int a, b, c;
    cin >> a >> b >> c;
	cout << ((a + (c % 2) > b) ? "First" : "Second") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solver();
    return 0;
}