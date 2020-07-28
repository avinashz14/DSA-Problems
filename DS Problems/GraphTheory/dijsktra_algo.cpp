//??......LekhanKarya..Nithost_16??
# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
# define testcase ll t=1; cin>>t; while(t--)
# define ll             long long
# define ull            unsigned long long
# define countbit       __builtin_popcount
# define gcd            __gcd
# define all(s)         s.begin(),s.end()
# define sz(x)          (int)((x).size())
# define pb(x)          push_back(x)
# define mp(x,y)        make_pair(x,y)
# define mod 1000000007
# define rep(i,j,n)  for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
# define flag(f) (f?"Yes":"No")<<"\n"
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
using namespace std;
const ll INF = 998244353;
typedef vector<vector<ll> > matrix;
typedef pair<int, int> pi; 
 
const int MaxN = 1e5 + 5;
vector<pair<int,ll> >G[MaxN];
ll dis[MaxN];
int n , m;
int pos[MaxN];

void dij(int k)
{
priority_queue< pair<ll,int> > que;
for(int i = 1; i <= n ; i++) dis[i] = LLONG_MAX;
dis[k] = 0LL;
que.push(make_pair(0LL,k));

while(!que.empty())
 {
	int now = que.top().second;
	//printf("now = %d ",now);
	que.pop();
	if(dis[now] == LLONG_MAX )break;
	int sz = G[now].size();
	for(int i = 0 ; i < sz ; i++){
		ll w = G[now][i].second;
		int to = G[now][i].first;
		//printf("to = %d ",to);
		if(dis[to] > dis[now] + w){
			dis[to] = dis[now] + w;
			pos[to] = now;
			que.push(make_pair(-dis[to],to));
		}
	}
	
  }
}
vector<int>  path_print(int s, int t)
{
	vector<int> path;

	for(int i=t; i!=s; i=pos[i])
	path.push_back(i);

	path.push_back(s);
	reverse(all(path));
	for(auto &i:path) cout<<i<<" ";
    return path;
}
//drive fun
int main(){

fast
cin>>n>>m; // n no. of vertexs and m no. of edges
while(m--){
	int u , v ;
	ll w;
	cin>>u>>v>>w;
	G[u].push_back(make_pair(v,w));
	G[v].push_back(make_pair(u,w));
}

return 0;
}

