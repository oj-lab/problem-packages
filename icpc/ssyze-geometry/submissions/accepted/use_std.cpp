#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,L;
    cin>>n>>L;
    vi x(2*n);
    ll ans=0;
    for(int i=0;i<n;i++) cin>>x[i];
    sort(x.begin(),x.begin()+n);
    for(int i=0;i<n;i++) x[i+n]=x[i]+L;
    for(int l=0,r=0;l<n;l++)
    {
        while(r<2*n&&(x[r]-x[l])*2<L) r++;
        int cc=(r-l-1);
        ans+=1LL*cc*(cc-1)/2;
    }
    ll tot=1LL*n*(n-1)*(n-2)/6;
    cout<<tot-ans<<'\n';
}