//https://codeforces.com/contest/1325/problem/A

# pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll            long long
# define clock         (clock() * 1000.0 / CLOCKS_PER_SEC)
# define fastio        ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define pb            push_back
# define mp            make_pair
# define lp(j,i,n)     for(j=i; j<n; j++)
# define lr(j,n,i)     for(j=n; j>=i; j--)
# define all(s)        s.begin(),s.end()
# define sz(x)         (int)((x).size())
# define mod           1000000007
using namespace std;

int main()
{
    int T=1;   cin>>T;
    while(T--)
    {
        ll x; cin>>x;
        ll a, b;
        a= x-1;
        b= 1;
        cout<<a<<" "<<b<<endl;
    }
}