#include <bits/stdc++.h>
using namespace std;

#ifndef USE_STDIN
#define USE_STDIN 0
#endif

class Solution
{
public:
    int findKthLargest(vector<int> &a, int k)
    {
        int n = a.size();
        nth_element(a.begin(), a.begin() + n - k, a.end());
        return a[n - k];
    }
};

int main()
{
    Solution s;
    if (USE_STDIN)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << s.findKthLargest(a, k) << endl;
    }
    else
    {
        vector<int> a = {3, 2, 1, 5, 6, 4};
        cout << s.findKthLargest(a, 2) << endl;
    }
    return 0;
}