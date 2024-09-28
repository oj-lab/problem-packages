#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const ll inf = 2e18 + 100;

struct car {
    int pos;
    int speed;
    int type;
} c[maxn];

int n, k, le[maxn], ri[maxn];
pair<ll, pair<ll, ll>> b[maxn];

bool check(ll t) {
    for (int i = 1; i <= n; ++i) {
        ll pos = c[i].pos + t * c[i].speed;
        b[i] = {pos, {i, c[i].type}};
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i) {
        if (i != 1 && b[i].first == b[i - 1].first && b[i].second.second != b[i - 1].second.second) return false;
        else if (i < le[b[i].second.first] || i > ri[b[i].second.first]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> c[i].pos >> c[i].speed >> c[i].type;
    sort(c + 1, c + 1 + n, [&](car &a, car &b) { return a.pos < b.pos; });
    for (int i = 1; i <= n; ++i) {
        if (c[i].type == c[i - 1].type) le[i] = le[i - 1];
        else le[i] = i;
    }
    for (int i = n; i >= 1; --i) {
        if (c[i].type == c[i + 1].type) ri[i] = ri[i + 1];
        else ri[i] = i;
    }
    ll l = 0, r = 2e9 + 10, ans = inf;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if (ans == 2e9 + 10) cout << "-1\n";
    else cout << ans << '\n';
}