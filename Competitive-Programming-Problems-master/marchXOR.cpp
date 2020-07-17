# include <bits/stdc++.h>
# define ll long long 
using namespace std;
void solve()
{
   int n,q; cin>>n>>q;
     ll a[n+3];
        int O=0, E=0;
       for(int i=0; i<n; i++)
        {
             cin>>a[i];
             if(__builtin_popcount(a[i])&1) O++;
             else E++;
        }
        for(int i=0; i<q; i++)
        {
              int p; cin>>p;
              if(__builtin_popcount(p)%2==0)
              cout<<E<<" "<<O<<"\n";
              else 
              cout<<O<<" "<<E<<"\n";
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--)
    {
        solve();
    }
}