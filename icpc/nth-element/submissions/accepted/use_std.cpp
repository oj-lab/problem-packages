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
    vector<int> a = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(a, 2) << endl;
    return 0;
}