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
void solve()
{

}
int main()
{
    fastio
    int t,s; cin>>t>>s; 
    if(s==1)
    {
      while(t--)
      {
        int n; cin>>n; 
        int a[n+1];
        int b[n+1];
       for(int i=0; i<n; i++)  cin>>a[i];
       for(int i=0; i<n; i++)  cin>>b[i];
        int aa=0, bb=0;
        sort(a, a+n);
        sort(b, b+n);
        int check =0;
        vector<int> v;

        if(a[0]<b[0])
        {
           v.push_back(a[0]);
           v.push_back(b[0]);
           for(int i=1; i<n; i++)
           {
               if(a[i]>=b[i])
               {
                   chech=-1;
                   break;
               }
               if(!binary_search(v.begin(), v.end(), a[i]))  
               {
                   chech=-1;
                   break;
               }
           }
        }
        
        else check=-1;
         
        if(check==-1)  cout<<"NO\n";
        else cout<<"YES\n";
      }
    }
    else
    {
      while(t--)
      {
        int n; cin>>n; 
        int a[n+1];
        int b[n+1];
       for(int i=0; i<n; i++)  cin>>a[i];
       for(int i=0; i<n; i++)  cin>>b[i];
        int aa=0, bb=0;

        lp(i,0,n)
        {
            aa^=a[i];
        }
         lp(i,0,n)
        {
            bb^=b[i];
        }
        if((aa<=bb))   cout<<"YES\n";
        else cout<<"NO\n";
      }
    }
}