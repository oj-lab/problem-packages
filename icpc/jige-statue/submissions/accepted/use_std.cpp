#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ": " << (x) << endl
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=1e6+7,inf=0x3f3f3f3f,mod=998244353;

ll a[maxn],pre[maxn],suf[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    pre[0]=1;
    for(int i=1;i<=n;++i) cin>>a[i],pre[i]=pre[i-1]*a[i]%mod;
    suf[n+1]=1;
    for(int i=n;i>=1;--i) suf[i]=suf[i+1]*a[i]%mod;
    for(int i=1;i<=n;++i) cout<<pre[i-1]*suf[i+1]%mod<<" \n"[i==n];
    return 0;
}