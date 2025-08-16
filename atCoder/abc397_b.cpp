#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int okay = 0;
    char req = 'i';
    for (char c : S) {
        if (c == req) {
            okay++;
            req = (req == 'o' ? 'i' : 'o');
        }
    }
    if (okay % 2 == 1) okay--;
    cout << (S.size() - okay) << "\n";
    return 0;
}