#include <bits/stdc++.h>
using namespace std;

void solver(void){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &i : a) cin >> i;
    int count = 0;
    for(int i = n - 2; i >= 0; i--){
        while(a[i] >= a[i + 1] && a[i] > 0){
            a[i] /= 2;
            count++;
        }
        if(a[i] == a[i+1]){
            cout << -1 << '\n';
            return;
        }
    }
    cout << count << '\n';
}

int main(void) {
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}
