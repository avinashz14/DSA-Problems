
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int t;
    cin >>t;
    while(t--)
    {
      int n;
      cin >>n;
      ll a[n];
      ll sum =0,c=0;
      for(int i=0; i<n; i++)
       {
         cin >>a[i];
       }
     int temp1=0;
     int temp2=0;
     int temp3=0;

      for(int i=0; i<n-1; i++)
      {
         temp2=0;
         for(int j=i+1; j<n; j++)
         {
             temp2=temp2^a[j-1];
             temp3=0;
            for(int k=j; k<n; k++)
            {
                temp3=temp3^a[k];
               if(temp2==temp3)
                {
                  c++;
                }
            }
         }
      }
       cout<<c<<endl;
    }

	return 0;
}
