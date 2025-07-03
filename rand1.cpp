#include <bits/stdc++.h>
using namespace std;

double func(double x) {
    return x * x;
}

double root(double (*f) (double), int n, int m) {
    double result = 0;
    for (int i = n; i <= m; i++) 
        result += f(i);
    return result;
}

signed main(void) {
    int n = 0, m = 10;
    double res = root(&func, n, m);
    cout << res << endl;
    exit(EXIT_SUCCESS);
}