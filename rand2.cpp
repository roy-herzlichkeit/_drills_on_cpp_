#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

template <class F>
double integrate(F f, double a, double b, int n = 1'000) {
    if (n % 2)
        ++n;
    const double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i & 1 ? 4.0 : 2.0) * f(x);
    }
    return sum * h / 3.0;
}

template <class F>
double derivative(F f, double x, double h = 1e-5) {
    return (-f(x + 2 * h) + 8 * f(x + h) - 8 * f(x - h) + f(x - 2 * h)) / (12 * h);
}

double square(double x) { 
    return sin(x); 
}

int main()
{
    double a = 0, b =  2 * PI;
    cout << "∫ from " << a << " to " << b << " ≈ "
         << integrate(square, a, b) << '\n';

    double x0 = PI / 4;
    cout << "d/dx at x = " << x0 << " ≈ "
         << derivative(square, x0) << '\n';
}