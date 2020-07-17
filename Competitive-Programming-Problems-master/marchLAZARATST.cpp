# include <bits/stdc++.h>
using  namespace std;
# define ll long long 
const int mxN=1e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--)
    {
       int n,m,k,q; cin>>n>>m>>k>>q;
       ll ql[mxN], qr[mxN], ans[mxN];
      for(int i=0;i<q; i++)
        {
            cin>>ql[i]>>qr[i];
        }
      if(k==3)
      {
          for(int i=0; i<q; i++)
          {
               ans[i]=m-1;
          }
      }
      cout<<2<<endl;
      for(int i=0; i<q; i++)
        cout<<ans[i]<<"\n";

        int ss; cin>>ss;
        if(ss==1)  continue;
        else return 0;
    }
    else 
    {
        for(int i=0; i<q; i++)
        {
          cout<<1<<" "<<ql[i]<<" "<<qr[i]<<" "<<m/2;
          int t; cin>>t;
          ans[i]=t;
        }
        cout<<2<<endl;
      for(int i=0; i<q; i++)
        cout<<ans[i]<<"\n";

        int ss; cin>>ss;
        if(ss==1)  continue;
        else return 0;
    }
}   