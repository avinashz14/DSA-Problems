/*
SPOJ---nithost16
MINSTOCK-
#tree #heap #binary-search #priority-queue

Tue May 12 11:42:12 IST 2020

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
    int t; cin>>t;
    int i=0;
    map<ll, string> m;
    map<string, ll> map1;
    set<ll> cost;
    string ss;
    ll yy;
    while(t--)
    {
         int n; cin>>n;
         i++;
         if(n==1)
         {
              cin>>ss>>yy;
              cost.insert(yy);
              m[yy]=ss;
              map1[ss]=yy;
         }
         else if(n==2)
         {
              cin>>ss>>yy;
              cost.erase(map1[ss]);
              cost.insert(yy);
              m[yy]=ss;
              map1[ss]=yy;
         }
         else 
         {
              cin>>ss;
              ll minn= *(cost.begin());
              cost.erase(minn);
              cout<<m[minn]<<" "<<i<<"\n";
         }
    }
    return 0;
}
