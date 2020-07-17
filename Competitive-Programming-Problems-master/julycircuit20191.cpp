#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long mod=1000000007;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        string s;
        cin>>s;
        int i=0, a=0, b=0, c=0, fb=0;
        while(s[i]!=0)
        {
            while(int(s[i])==40)
            {
                a++;
                if(fb==1)
                {
                   a--;
                   b--;
                   c++;
                   fb=0;
                }
                i++;
            }
            if(int(s[i])==41)
            {
             while(int(s[i])==41)
               {
                b++;
                i++;
                fb=1;
               }
            }
        }
        if(c&1)
        cout<<a+b+(c-1)<<endl;
        else
        cout<<a+b+c<<endl;
    }
}
