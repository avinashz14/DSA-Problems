# include <bits/stdc++.h>
# define ll long long 
using namespace std;
const int INF = 998244353;
int  dp[500];
int main()
{
    int n, k; cin>>n;
    int  a[n+1];
    for(int i=1; i<=n; i++)  cin>>a[i];
     
    for(int i=0; i<500; i++)
    {
           dp[i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j] && dp[i] < dp[j]+1)  dp[i] = dp[j]+1;
            
        }
    }
    int l=0;
     for(int i=0; i<=n; i++)
    {
       l=max(l, dp[i]);
    }
    cout<<"\nlength of longest Inreacing Sequence is "<<l<<"\n";

    int i=n;
    while(dp[i]!=l)  i--;
    stack<int> s;
    int cur =a[i];
    l--;
    s.push(cur);
    while(l!=0)
    {
        i--;
        if( dp[i]==l && a[i]<cur)
        {
            cur = a[i];
            s.push(cur);
            l--;
        }
    }
    while(s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}