#include <bits/stdc++.h>
using namespace std;

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << s.findKthLargest(a, k) << endl;
    return 0;
}