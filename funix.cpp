# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define fastio ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define pb push_back
# define mp make_pair
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define mod 1000000007
# define mz 100000
using namespace std;

int main()
 {
	 fastio
	int t; cin>>t; 
	while (t--)
	{
		int n; cin>>n;
		int p[n+1][2], s=0, sm=INT_MAX;
		for(int i=0; i< n; i++)
		{
			int x, y; cin>>x>>y;
			p[i][0]=x, p[i][1]=y; 
			if(sm > x) { s=i; sm =x;}
		//	cout<<x<<" ";
		}
	     
	  ll sum =0, a=p[s][0],b=p[s][1];
	     for(int i=s+1; i!=s; i=(i+1)%n)
       	{    i=(i)%n;
		   	//	cout<<a<<"A ";
              sum+=abs(min(b-p[i][0], a))+1;
			   a=p[i][0]-b,b=p[i][1];
     	}
		 cout<< sum<<"\n";
	}
	
    
	return 0;
}
