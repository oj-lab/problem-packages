#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int MAXN = 100;
inline void add(int &a, int b) {
    if ((a += b) >= mod) {
        a -= mod;
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::vector<int> dp(MAXN + n + 1);
        int ans = 0;
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            int t = 0;
            for (int j = i + 1; j; j -= j & -j) {
                add(t, dp[j]);
            }
            add(ans, t + 1);
            for (int j = x + i + 1; j < dp.size(); j += j & -j) {
                add(dp[j], t + 1);
            }
        }
        printf("%d\n", (ans - n + mod) % mod);
    }
}
