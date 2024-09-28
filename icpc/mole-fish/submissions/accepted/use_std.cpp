#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ": " << (x) << endl
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=1e6+7,inf=0x3f3f3f3f,mod=1e9+7;

int a[]={16,24,54,80,10000};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    double ans=0;
    for(int i=0;i<n;++i)
    {
        string s;double p;
        cin>>s>>p;
        if(s=="D") ans+=p*a[0];
        else if(s=="C") ans+=p*a[1];
        else if(s=="B") ans+=p*a[2];
        else if(s=="A") ans+=p*a[3];
        else ans+=p*a[4];
    }
    ans-=23;
    cout<<fixed<<setprecision(4)<<ans*k<<'\n';
    return 0;
}