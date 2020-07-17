//
//  main.cpp
//  practice
//
//  Created by nithost16 on 05/06/2020.
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
# define mod 1000000000
# define rep(i,j,n) for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
using namespace std;
const ll INF = 998244353;
typedef vector<vector<ll> > mat;
int k=0;

mat mul(mat a, mat b)
{
     mat c(k+1, vector<ll> (k+1));
     rep(i, 1, k+1) 
       rep(j, 1, k+1) 
         rep(l, 1, k+1) 
           c[i][j]=(c[i][j] + 1ll*a[i][l]* b[l][j])%mod;

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

int main()
{
    int t; cin>>t;

    while(t--)
    {
    
       cin>>k;
       vector<ll> b(k+1);
       vector<ll> c(k+1);

       for(int i=1; i<=k; i++)  cin>>b[i];
       
       for(int i=1; i<=k; i++)  cin>>c[i];

       ll n; cin>>n;

       if(n <=k)  cout<<b[n]<<"\n";
       else{
          mat a(k+1, vector<ll> (k+1));
          ll res =0;
         rep(i, 1, k)
            a[i][i+1]=1;
            
         rep(i, 1, k+1)
            a[k][i]=c[k+1-i];
            
          a = pow(a, n-1);

          rep(i, 1, k+1)
            res = (res+ a[1][i]*b[i])%mod;
        
        cout<<res<<"\n";
       }
    }
}