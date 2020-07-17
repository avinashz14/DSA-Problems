//
//  main.cpp
//  practice
//
//  Created by nithost16 on 06/06/2020.
//  Copyright © 2020 NITHOST16. All rights reserved.
//

/*
 O(T * K^3 * log(N)) solution by matrix exponentation
 I strongly recommend you to learn how to build transformation by from the following resource.
 http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
 */

# include "bits/stdc++.h"
# define ll long long
# define ull unsigned long long
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())

template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }

# define mod 1000000009
# define rep(i,j,n) for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
using namespace std;
const ll INF = 998244353;
typedef vector<vector<ll> > mat;
int k=0, p;

mat mul(mat a, mat b)
{
     mat c(17, vector<ll> (17));
     rep(i, 1, k+2) 
       rep(j, 1, k+2) 
         rep(l, 1, k+2) 
           c[i][j]=(c[i][j] + 1ll*a[i][l]* b[l][j])%p;

    return c;
}

mat pow(mat a, ll p)
{
    if(p==1) 
      return a;
    if(p%2)
        return mul(a, pow(a, p-1));
    mat x = pow(a, p/2);
    return mul(x, x);
    
}
ll sum (mat a, ll n, vector<ll> b)
{
    ll res=0; 
    if(n <= k)
    {
        for(int i=0; i<n; i++)
           res = (res+b[k-i])%p;
    }
    else 
    {
    mat t = pow(a, n-k);
     rep(i, 1, k+2)
        res =(res+ t[k+1][i]*b[i])%p;
    }
   return res;
}
 
int main()
{
    int t; cin>>t;

    while(t--)
    {
    
       cin>>k;
       vector<ll> b(17);
       vector<ll> c(17);

       for(int i=k; i>0; i--)  cin>>b[i], b[k+1]+=b[i];
       
       for(int i=1; i<=k; i++)  cin>>c[i];

       ll m, n; cin>>m>>n>>p;

          mat a(17, vector<ll> (17));
          ll res =0;
         
         rep(i, 2, k+1)
            a[i][i-1]=1;
            
         rep(i, 1, k+1)
          {
              a[1][i]=c[i];
              a[k+1][i]=c[i];
          }
         a[k+1][k+1]=1;
        
        ll l = sum(a, m-1, b);
        ll r = sum(a, n, b); 

         res  = (r-l+p)%p;
        cout<<res<<"\n";
    }
}
