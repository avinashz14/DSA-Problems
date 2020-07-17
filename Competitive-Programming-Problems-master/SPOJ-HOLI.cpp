//............@NITHOST16...........//
# include "bits/stdc++.h"
# define ll long long
# define ull unsigned long long
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())

//template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
//template< class T > T min(T a, T b) { return (a < b ? a : b); }

# define mod 1000000000
# define rep(i,j,n) for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
using namespace std;
const ll INF = 998244353;
typedef vector<vector<ll> > mat;

ll n, ret=0;
vector<pair<ll, ll> > adj[100005];


ll dfs(ll pre, ll u)
{
    ll ans=1;
    for(int i=0; i<adj[u].size(); i++)
    {
      ll v = adj[u][i].first;
      ll wt = adj[u][i].second;
      
      if(v==pre) continue;
      ll nodes = dfs(u, v);
      cout<<"V "<<u<<"-"<<v<<"-"<<2*min(nodes, n-nodes)*wt<<"\n";
      ret+=2*min(nodes, n-nodes)*wt;
      ans+=nodes;
    }
    return ans;
}

int main()
{
    ll t, tc=1; cin>>t;
    while(t--)
    {
       ret=0;
       cin>>n;
       
       rep(i,1, n+1)
         adj[i].clear();
       
       rep(i, 1, n)
        {
         ll x, y, w; cin>>x>>y>>w;
         adj[x].push_back({y, w});
         adj[y].push_back({x, w});
        }
        
       dfs(-1, 1);
       cout<<"Case #"<<tc<<": "<<ret<<"\n";
       tc++;
    }
}
