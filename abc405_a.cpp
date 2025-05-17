#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int R, X;
  bool flag = true;
  cin >> R >> X;
  if (X == 1) {
    if (R >= 1600 && R <= 2999)
      flag = false;
  } else {
    if (R >= 1200 && R <= 2399) 
      flag = false;
  }
  cout << (flag ? "No" : "Yes") << "\n";
  return 0;
}