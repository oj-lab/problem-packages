#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vi a(n);
		vi cnt(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cnt[a[i]]++;
		}
		vector<ll> s, t;
		for (int i = 0; i <= n; i++)
		{
			if (!cnt[i])
				continue;
			if (cnt[i] & 1)
				s.push_back(i);
			else
				t.push_back(i);
		}
		for (auto u : t)
			s.push_back(u);
		if (t.size() & 1)
		{
			sort(s.begin(), s.end());
			s = vector<ll>(s.begin() + 1, s.end());
		}
		cout << accumulate(s.begin(), s.end(), 0LL) << '\n';
	}
	return 0;
}
