#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define repr(i,j,n) for(i=j;i<=n;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];
vector<vector<ll> > graph(maxn);
vector<ll> post;
bool visited[maxn];

void dfs(ll u){
    visited[u]=true;
    vector<ll> n=graph[u];
    for(int i=0;i<n.size();i++){
        if(!visited[n[i]]) dfs(n[i]);
    }
    post.pb(u);
}
int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n,u,v;
    cin>>n>>m;
    rep(i, m){
        cin>>j>>k;
        graph[j].pb(k);
    }
    repr(i, 1, n){
        if(!visited[i]){
             dfs(i);
         }
    }
    reverse(post.begin(), post.end());
    rep(i, n) cout<<post[i]<<" ";
    cout<<endl;
}
