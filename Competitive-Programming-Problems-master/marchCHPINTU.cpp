# include <bits/stdc++.h>
# define ll long long 
using namespace std;
void solve()
{
        int n, m; cin>>n>>m;
        int fr[n+1];
        map<int, int> mm;
        for(int i=0; i<n; i++) 
         { 
                cin>>fr[i];
         }
        int z;
        for(int i=0; i<n; i++) 
        {
             cin>>z;
            mm[fr[i]]+=z;
        }
        int ans = INT_MAX;
        for(auto &i: mm)
        {
            if(ans > i.second) ans = i.second;
        }
        cout<<ans<<"\n";
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}