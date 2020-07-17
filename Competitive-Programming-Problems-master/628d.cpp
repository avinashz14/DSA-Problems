 # pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll            long long
# define clock         (clock() * 1000.0 / CLOCKS_PER_SEC)
# define fastio        ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define pb            push_back
# define mp            make_pair
# define lp(j,i,n)     for(int j=i; j<n; j++)
# define lr(j,n,i)     for(int j=n; j>=i; j--)
# define all(s)        s.begin(),s.end()
# define sz(x)         (int)((x).size())
# define mod           1000000007
using namespace std;

int main()
{
    ll u,v; cin>>u>>v;
    
    if(u==0 && v==0){ cout<<0<<endl; }
    else if(u > v)  cout<<-1<<endl;
    else 
    {
      ll dif = v- u;
      ll rif = dif/2;
      ll sif = rif^u;
      if(dif&1)  cout<<-1<<endl;
      else {
        
         if(dif==0)
          {
          cout<<1<<endl;
          cout<<u<<endl;
          }
         else if(u+rif==sif)
          {
          cout<<2<<endl;
          cout<<sif<<" "<<rif<<endl;
          }
         else
         {
          cout<<3<<endl;
          cout<<rif<<" "<<rif<<" "<<u<<endl;
         }
      }      
    }
}