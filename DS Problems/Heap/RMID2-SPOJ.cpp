/*
SPOJ---nithost16
RMID2 - Running Median Again
#tree #heap #binary-search #priority-queue

Mon May 11 2020, 14:49:38 IST 

Solution using two priority quequ min and max heap 

use fast_io for strict limits
use printf/scanf  instead of cout/in for faster 


*/
//??......LekhanKarya..Nithost_16??
# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
# define ll             long long
# define clock           (clock() * 1000.0 / CLOCKS_PER_SEC)
# define countbit       __builtin_popcount
# define gcd            __gcd
# define ull unsigned long long
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define mod 1000000007
# define rep(i,j,n) for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
using namespace std;
const ll INF = 998244353;
typedef vector<vector<ll> > matrix;
typedef pair<int, int> pi; 


int main()
{
     fast
     ll t;scanf("%lld", &t); 
     while(t--)
     {
       ll n; 
       priority_queue<ll, vector<ll> , greater<ll> > high;
       priority_queue<ll> low;
       ll l=0, h=0;
       high.push(-1);
       low.push(2000000000);
       while(1)
       {
             scanf("%lld", &n); 
             if(n==0) break;
             if(n==-1)
             {
                  if(h> l && high.top()!=-1)
                  printf("%lld\n", high.top()), high.pop(), h--;
                  else if(low.top()!=2000000000)
                  printf("%lld\n", low.top()), low.pop(), l--;
             }
             else 
             {
                  if(n> high.top())
                  {
                       h++;
                       high.push(n);
                      // printf("%lldHIGH ", high.top());
                       if(high.top()==-1)
                       high.pop();
                  }
                  else 
                  {
                       l++;
                       low.push(n);
                     //   printf("%lldLOW ", low.top());
                       if(low.top()==2000000000)
                       low.pop();
                  }
             }
             ll diff = h-l;
             ll abs = (diff>=0)?diff:diff*(-1);
             while(abs>1)
             {
                if(diff>0)
                {
                     low.push(high.top());
                     high.pop();
                     h--;
                     l++;
                     abs-=2;
                    if(low.top()==2000000000)
                       low.pop();
                }
                else 
                {
                     high.push(low.top());
                     low.pop();
                     l--;
                     h++;
                     abs-=2;
                     if(high.top()==-1)
                       high.pop();
                }
             }
       }
       printf("\n"); 
     }
}