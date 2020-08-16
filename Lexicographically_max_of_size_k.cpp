/*Given a string find lexicographically max/min subsequence of size k 

solutions:
1. O(NlogN) |  O(N) space 
using range query - segmentTree/fenwickTree 
2. O(N) | O(K) space
using single stack 

2. one is implemented here */

/*
e.g  input: abczabc  3
     output:  zbc

     input: abcabzc  3
     output:  czc
*/

#include "bits/stdc++.h"
using namespace std;

string male(string s, int k)
{
    stack<char> st;
    int n = s.size();
    
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && (st.top()< s[i] && (n-i+st.size()-1>=k)) )   // this (n-i+st.size()-1>=k to maintain size k string 
        {
            st.pop();
        }
        st.push(s[i]);
    } 
    string ss;
    while(!st.empty())
    {
          ss+=st.top();
          st.pop();
    }
    reverse(ss.begin(), ss.end());
    return ss;
}

int main()
{
 string s; cin>>s; 
 int k; cin>>k;
 
 cout<<male(s, k)<<endl;
 
 return 0;
 }

