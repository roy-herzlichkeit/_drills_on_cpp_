#include <bits/stdc++.h>
using namespace std;

void solver();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solver();
	return 0;
}

void solver()
{
	int n;
	cin >> n;
	vector<int> A(n, 0);
	int count = 0;
	bool inSegment = false;
	for (int a : A)
	{
		cin >> a;
		if (a != 0)
		{
			if (!inSegment)
			{
				count++;
				inSegment = true;
			}
		}
		else
		{
			inSegment = false;
		}
	}
	cout << min(2, count) << endl;
}
