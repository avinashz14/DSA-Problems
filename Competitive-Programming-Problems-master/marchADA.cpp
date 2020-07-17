# include <bits/stdc++.h>
# define ll long long 
using namespace std;
void solve()
{
    int r1,c1; cin>>r1>>c1;
         int box[][2]={{1,1},{2,2},{1,3},{2,4},{1,5},{2,6},{1,7},{2,8},{3,7},{4,8},{5,7},{6,8},{7,7},{8,8},{3,3},{4,4},{3,5},{4,6},{5,5},{6,6},{7,5},{8,6},{3,1},{4,2},{5,3},{6,4},{7,3},{8,4},{5,1},{6,2},{7,1},{8,2}};
        
        int mv=31, fr=31, f=1;
        int mc = (r1+c1)/2;
        if(r1!=mc) mv+=2;
        else if(mc!=1) mv++;
        else f=0;
         
          cout<<mv<<endl;
          if(fr+2==mv)  cout<<mc<<" "<<mc<<endl;
          for(auto &i: box)
           {    
               if(f)
               cout<<i[0]<<" "<<i[1]<<endl;
               f=1;
           }          
}
int main()
{
    int t; cin>>t;
    while(t--)
      {
         solve();
      }
}