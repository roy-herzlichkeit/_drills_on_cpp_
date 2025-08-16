#include <bits/stdc++.h>
using namespace std;

void solver()
{
    int size;
    cin >> size;
    vector<int> vals(size);
    for (auto &val : vals)
        cin >> val;
    for (int i = 0; i + 1 < size; ++i)
    {
        if (vals[i] == 0 && vals[i + 1] == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    vector<int> duelWin(size - 1, -1);
    for (int i = 0; i < size; ++i)
    {
        if (vals[i] == 0)
        {
            if (i > 0)
            {
                int duelId = i - 1;
                int forcedWin = i - 1;
                if (duelWin[duelId] == -1)
                    duelWin[duelId] = forcedWin;
                else if (duelWin[duelId] != forcedWin)
                {
                    cout << "YES\n";
                    return;
                }
            }
            if (i + 1 < size)
            {
                int duelId = i;
                int forcedWin = i + 1;
                if (duelWin[duelId] == -1)
                    duelWin[duelId] = forcedWin;
                else if (duelWin[duelId] != forcedWin)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    vector<int> winCount(size, 0);
    for (int d = 0; d < size - 1; ++d)
    {
        if (duelWin[d] != -1)
            ++winCount[duelWin[d]];
    }
    vector<int> needsWin;
    for (int i = 0; i < size; ++i)
    {
        if (vals[i] == 1 && winCount[i] == 0)
            needsWin.push_back(i);
    }
    vector<int> freeCount(size, 0);
    for (int d = 0; d < size - 1; ++d)
    {
        if (duelWin[d] == -1)
        {
            freeCount[d]++;
            freeCount[d + 1]++;
        }
    }
    for (int idx : needsWin)
    {
        if (freeCount[idx] == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    for (int d = 0; d < size - 1; ++d)
    {
        if (duelWin[d] == -1)
        {
            int left = d;
            int right = d + 1;
            bool leftReq = find(needsWin.begin(), needsWin.end(), left) != needsWin.end();
            bool rightReq = find(needsWin.begin(), needsWin.end(), right) != needsWin.end();
            if (leftReq && rightReq && freeCount[left] == 1 && freeCount[right] == 1)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solver();
    }
    return 0;
}