# include "bits/stdc++.h"
# define ll long long
# define ull unsigned long long
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define mod 1000000007
# define Fo(i,n) for(int i=0; i<n; i++)
# define Fr(i,n) for(int i=n-1; i>=0; i--)
using namespace std;
const int mxN = 1e5;

int main()
{
   int t; scanf("%d", &t);
   while (t--)
   {
       int n, m,k;
       scanf("%d %d %d", &n, &m, &k);
       
       int add[k];
       memset(add,0, k);

       vector<int> q[n+1];

       Fo(i,n)
       {
           Fo(j, k)
           {
               int a; cin>>a;
               q[i].push_back(a);
           }
       }
       vector<int> ans, ans2 ; vector<int> ff ;  vector<int> bf;
       Fo(i,n)
       {
           int a[10]={0}, len=0;
           Fo(j, k)
           {
              if(!add[j])
                   a[q[i][j]]++;
              else
                  len++; 
           }
           int m = INT_MIN, idx=0;
           for(int j=1; j< 10; j++)
           {
              if(a[j]<m) m=a[j], idx=j;
           }
           for(int j=0;j<k; j++)
           {
               if(q[i][j]==idx)  add[j]=1;
           }
           if(len!=k)
             ff.push_back(m), ans.push_back(idx);
           else 
             ff.push_back(1), ans.push_back(q[i][0]);

       }
    memset(add, 0, k);
      Fr(i,n)
       {
           int a[10]={0}, len=0;
           Fr(j, k)
           {
              if(!add[j])
                   a[q[i][j]]++;
              else
                  len++; 
           }
           int m = INT_MIN, idx=0;
           for(int j=1; j< 10; j++)
           {
              if(a[j]<m) m=a[j], idx=j;
           }
           for(int j=0;j<k; j++)
           {
               if(q[i][j]==idx)  add[j]=1;
           }
           if(len!=k)
             bf.push_back(m), ans2.push_back(idx);
           else 
             bf.push_back(1), ans2.push_back(q[i][0]);

       }
       int cn1 =0, cn2=0, siz = sz(bf);
       for(int i=0; i<siz; i++)
       {
           if(bf[i]> ff[i])   cn2++;
           else cn1++;
       }
       if(cn1 > cn2)
       {
           for(auto &i : ans)  cout<<i<<" ";
       }
       else
       {
           for(auto &i : ans2)  cout<<i<<" ";
       }


       cout<<"\n";
   }
   
}
