# include <bits/stdc++.h>
# define ll long long 
using namespace std;
const int mxN=1e5;
int n, q, a[mxN], ans[mxN], qr[mxN], ql[mxN], qy[mxN], ft[mxN];

void upd(int i, int x)
{
     for(++i, i<n; i+=i &-i)
       ft[i]+=x;
}
int qry(int i)
{
     int r=0;
     for(; i; i-=i&-i)
       r+=ft[i];

      return r;
}
struct event{
     int y, t, i;
     bool operator<(const event &o) const{
          return  make_pair(y,t)<make_pair(o.y, o.t);
     }
}

void solve()
{
        cin>>n>>q;
        for(int i=1; i<n+1; i++)
             cin>>a[i];
        for(int i=0; i<q; i++)
        {
             cin>>ql[i]>>qr[i]>>qy[i], --ql[i], --qr[i];
        }
     
        vector<event> ve;
        for(int i=0; i+1<n; i++)
        {
             ve.push_back(min(a[i], a[i+1]), 1, i);
             ve.push_back(max(a[i], a[i+1]), 3, i);
        }    

        for(int i=0; i<q; i++)
        {
             ve.push_back(qy[i], 2, i);
        }

        sort(ve.begin(), ve.end());
        for(event e: ve)
        {
             if(e.t==1)
             {
                  upd(e.i, 1);
             }
             else if(e.t==2)
             {
                   ans[e.i]=qry(qr[e.i]-ql[e.i]);
             }
             else 
                upd(e.i, -1);
        }


        for(int i=0; i<q; i++)
         cout<<ans[i]<<"\n";
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