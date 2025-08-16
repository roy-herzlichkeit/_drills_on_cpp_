#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A)
        cin >> a;
    unordered_map<int, int> LFREQ, RFREQ;
    for (int i = 0; i < N; i++)
        RFREQ[A[i]]++;
    int LEFT = 0, RIGHT = RFREQ.size(), MAX = 0;
    for (int i = 0; i < N - 1; i++){
        LFREQ[A[i]]++;
        if(LFREQ[A[i]] == 1)
            LEFT++;
        RFREQ[A[i]]--;
        if(RFREQ[A[i]] == 0) {
            RFREQ.erase(A[i]);
            RIGHT--;
        }
        MAX = max(MAX, LEFT + RIGHT);
    }
    cout << MAX << "\n";
    return 0;
}