#include <bits/stdc++.h>
 
constexpr const int MAXN = 35;
int w[MAXN], a[MAXN];
 
using i64 = long long;
 
int ch[(1 << 17) * 17][2];
i64 dp[(1 << 17) * 17];
int sz = 0;
void insert(int w, i64 v) {
    int u = 0;
    for (int i = 31; ~i; i--) {
        dp[u] = std::max(dp[u], v);
        int c = w >> i & 1;
        if (!~ch[u][c]) {
            ch[u][c] = ++sz;
        }
        u = ch[u][c];
    }
    dp[u] = std::max(dp[u], v);
}
 
i64 query(int w, int m) {
    int u = 0;
    i64 ans = -1e9;
    for (int i = 31; ~i; i--) {
        int x = w >> i & 1, y = m >> i & 1;
        if (y) {
            if (~ch[u][x]) {
                ans = std::max(dp[ch[u][x]], ans);
            }
            x ^= 1;
        }
        if (!~ch[u][x]) {
            return ans;
        }
        u = ch[u][x];
    }
    return std::max(ans, dp[u]);
}
 
int main() {
 
    int n, m;
    std::cin >> n >> m;
    
    memset(ch, -1, sizeof(ch));
    memset(dp, 0xc0, sizeof(dp));
 
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
 
    for (int i = 0; i < (1 << (n / 2)); i++) {
        int W = 0;
        i64 value = 0;
        for (int j = 0; j < n / 2; j++) {
            if (i >> j & 1) {
                W ^= w[j];
                value += a[j];
            }
        }
        insert(W, value);
    }
    i64 ans = 0;
    for (int i = 0; i < (1 << (n - n / 2)); i++) {
        int W = 0;
        i64 value = 0;
        for (int j = 0; j < (n - n / 2); j++) {
            if (i >> j & 1) {
                W ^= w[n / 2 + j];
                value += a[n / 2 + j];
            }
        }
        ans = std::max(ans, query(W, m) + value);
    }
    std::cout << ans << std::endl;
}