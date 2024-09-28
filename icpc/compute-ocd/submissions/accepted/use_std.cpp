//Bit Tree
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
struct Bit{
	vc<ll> t;
	int sz;
	Bit(int n=1){
		sz=1;
		n+=2;
		while(sz<=n) sz*=2;
		t=vc<ll>(sz);
	}
	void add(int x,int v)
	{
		x++;
		while(x<sz)
		{
			t[x]+=v;
			x+=x&-x;
		}
	}
	ll query(int x)
	{
		x++;
		ll ret=0;
		while(x)
		{
			ret+=t[x];
			x-=x&-x;
		}
		return ret;
	}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	vi x(n+1);
	vi all;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		all.push_back(x[i]);
	}
	mkuni(all);
	auto getid=[&](int x){
		return lower_bound(all.begin(),all.end(),x)-all.begin();
	};
	for(int i=1;i<=n;i++) x[i]=getid(x[i]);
	ll sum=0;
	Bit T(n+1),cnt(n+1);
	for(int k=1;k<=n;k++)
	{
		sum+=all[x[k]];
		T.add(x[k],all[x[k]]);
		cnt.add(x[k],1);
		int L=1,R=k,ret=-1;
		while(L<=R)
		{
			int mid=L+R>>1;
			ll left=1LL*mid*a,ri=1LL*(k-mid)*b;
			if(left>=ri)
			{
				R=mid-1;
				ret=mid;
			}
			else L=mid+1;
		}
		assert(ret!=-1);
		L=0,R=n;
		int tar=-1;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(cnt.query(mid)>=ret)
				R=mid-1,tar=mid;
			else L=mid+1;
		}
		//dbg(ret,tar);
		assert(tar!=-1);
		int val=all[tar];
		int cc=cnt.query(tar);
		ll ans=a*(1LL*cc*val-T.query(tar))+1LL*b*(sum-T.query(tar)-1LL*(k-cc)*val);
		print(ans);
	}
}