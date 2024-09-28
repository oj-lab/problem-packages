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
const int maxn = 1e7 + 10;
int prime[maxn] = {0}, phi[maxn] = {0}, tot;
bool vis[maxn];

void euler()
{
    phi[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!phi[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++)
        {
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}

struct maxmatching{
	struct E{int a,b;};
	const vvc<int>&g;
	int n,sz;
	vi p,t,mt;
	vc<E> f;
	int non(int v){
		return t[v]!=sz||p[v]==-1?v:(p[v]=non(p[v]));
	}
	void R(int a,int b){
		int d=mt[a];
		mt[a]=b;
		if(d==-1||mt[d]!=a)return;
		if(f[a].b==-1){
			mt[d]=f[a].a;
			R(f[a].a,d);
		}else{
			R(f[a].a,f[a].b);
			R(f[a].b,f[a].a);
		}
	}
	bool arg(int rt){
		queue<int> q;
		t[rt]=sz;
		p[rt]=-1;
		f[rt]=E{-1,-1};
		q.push(rt);
		while(q.size()){
			int a=q.front();q.pop();
			for(auto b:g[a]){
				if(b==rt)continue;
				if(mt[b]==-1){
					mt[b]=a;
					R(a,b);
					return true;
				}
				if(t[b]==sz){
					int x=non(a),y=non(b);
					if(x==y)continue;
					int z=rt;
					while(x!=rt||y!=rt){
						if(y!=rt)swap(x,y);
						if(f[x].a==a&&f[x].b==b){
							z=x;
							break;
						}
						f[x]=E{a,b};
						x=non(f[mt[x]].a);
					}
					for(auto v:{non(a),non(b)}){
						while(v!=z){
							t[v]=sz;
							p[v]=z;
							q.push(v);
							v=non(f[mt[v]].a);
						}
					}
					continue;
				}
				if(t[mt[b]]==sz)continue;
				f[b]=E{-1,-1};
				t[mt[b]]=sz;
				p[mt[b]]=b;
				f[mt[b]]=E{a,-1};
				q.push(mt[b]);
			}
		}
		return false;
	}
	maxmatching(const vvc<int>&gg):g(gg),n(g.size()),sz(0),
		p(n),t(n,-1),mt(n,-1),f(n){
			for(int i=0;i<n;i++)
				if(mt[i]==-1)
				sz+=arg(i);
		}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n);
    vvc<int> pt(n);
    vi all;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        bool isp=1;
        int ta,tb;
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                isp=0;
                ta=j;
                tb=a[i]/j;
                break;
            }
        }
        if(isp)
        {
            pt[i].push_back(a[i]);
            vis[a[i]]=1;
        }
        else if(ta==tb)
        {
            pt[i].push_back(ta);
            vis[ta]=1;
        }
        else{
            pt[i].push_back(ta);
            pt[i].push_back(tb);
            all.push_back(tb);
            all.push_back(ta);
        }
    }
    mkuni(all);
    //dbg(all);
    auto getid=[&](int x){
        return lower_bound(all.begin(),all.end(),x)-all.begin();
    };
    int ans=0;
    for(int i=0;i<maxn;i++)
    {
        if(vis[i]) ans++;
    }
    vvc<int> g(all.size());
    for(int i=0;i<n;i++)
    {
        if(pt[i].size()==2&&!vis[pt[i][0]]&&!vis[pt[i][1]])
        {
            int aid=getid(pt[i][0]);
            int bid=getid(pt[i][1]);
            //dbg(i,aid,bid);
            g[aid].push_back(bid);
            g[bid].push_back(aid);
        }
    }
    print(ans+maxmatching(g).sz);
}