#include <bits/stdc++.h>
using namespace std;

#ifndef USE_STDIN
#define USE_STDIN 1
#endif

class Solution {
 public:
  vector<string> lin88_palindrome(string s, int q, vector<int>& pos,
                                  vector<char>& upd) {
    int cnt = 0, n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - i - 1]) cnt++;
    }
    vector<string> ans;
    for (int i = 0; i < q; ++i) {
      char c = upd[i];
      int p = pos[i] - 1;
      if (s[p] == s[n - p - 1]) {
        s[p] = c;
        if (s[p] != s[n - p - 1]) cnt++;
      } else {
        s[p] = c;
        if (s[p] == s[n - p - 1]) cnt--;
      }
      if (!cnt) {
        ans.push_back("Yes");
      } else {
        ans.push_back("No");
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  if (USE_STDIN) {
    string s;
    int q;
    cin >> s >> q;
    vector<int> pos(q);
    vector<char> upd(q);
    for (int i = 0; i < q; ++i) {
      cin >> pos[i] >> upd[i];
    }
    // for (auto& it : upd) cout << it << endl;
    vector<string> res = sol.lin88_palindrome(s, q, pos, upd);
    for (auto& it : res) cout << it << endl;
  } else {
    string s = "abc";
    int q = 3;
    vector<int> pos = {1, 2, 3};
    vector<char> upd = {'c', 'c', 'b'};
    vector<string> res = sol.lin88_palindrome(s, q, pos, upd);
    for (auto& it : res) cout << it << endl;
  }
  return 0;
}