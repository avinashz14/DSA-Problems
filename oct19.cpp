
# include "bits/stdc++.h"
# define ll long long
# define ull unsigned long long
# define fast ios_base::svnc_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define mod 1000000007
# define Fo(i,n) for(int i=0; i<n; i++)
# define Fr(i,n) for(int i=n-1; i>=0; i--)
using namespace std;
int ans =0;
vector<int> adj[20000];
int cnt=0;
void dfs(int s, int vis[])
{
    vis[s]=1;
     cnt++;
     //cout<<s+1<<" ";
    if(!adj[s].empty())
    {  
        int len = adj[s].size();
        for(int i=0; i< len; i++)
        {
            if(!vis[adj[s][i]])
              {  
                //vis[adj[s][i]]=1;
                dfs(adj[s][i], vis);
              }
        }
    }
    return 
    
}
int main()
{
    int n; cin>>n;  
    Fo(i, n)
    {
        int x; cin>>x;  x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
    } 
    int vis[n]={0};
    Fo(i, n)
    {
        cnt=0; 
       if(!vis[i])
       {
        dfs(i, vis);
       // cout<<cnt;cout<<"--\n";
         ans++;
       }
    }

    cout<<ans<<"\n";
                
}