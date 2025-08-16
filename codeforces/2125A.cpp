#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

typedef long long ll;

const int INF = 1e9 + 7;

inline static void solver(void);

void replaceAll(string &str, const string &from, const string &to)
{
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != string::npos)
    {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}

signed main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void)
{
    string s;
    cin >> s;
    if (s.find("FFT") == string::npos && s.find("NTT") == string::npos)
    {
        cout << s << '\n';
        return;
    }
    int cnt = 0;
    for (char c : s)
        if (c == 'T')
            cnt++;
    string ans;
    ans.reserve(s.size());
    ans.append(cnt, 'T');
    for (char c : s)
        if (c != 'T')
            ans.push_back(c);
    cout << ans << '\n';
}