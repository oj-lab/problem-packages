#include <bits/stdc++.h>
using namespace std;

#ifndef USE_STDIN
#define USE_STDIN 0
#endif

class Solution {
 public:
  int ssyze_hard_drive(int n, int s, vector<int> &a) {
    sort(a.begin(), a.end());
    long long ans = 0;
    if (s <= a[0])
      ans = (a.back() - s);
    else if (s >= a.back())
      ans = s - a[0];
    else
      ans = min(2ll * (s - a[0]) + (a[n - 1] - s),
                2ll * (a[n - 1] - s) + (s - a[0]));
    return ans;
  }
};

int main() {
  Solution sol;
  if (USE_STDIN) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << sol.ssyze_hard_drive(n, s, a) << endl;
  } else {
    vector<int> a = {5, 6, 5, 2, 1};
    cout << sol.ssyze_hard_drive(5, 2, a) << endl;
  }
  return 0;
}