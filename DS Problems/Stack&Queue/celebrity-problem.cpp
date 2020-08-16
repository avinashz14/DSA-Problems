
#include "bits/stdc++.h"
using namespace std;

/*
   @avinashz14
   #nithost_16
   celebrilty problem sol
   using Stack   Time complexity O(N) space O(N)
   using TwoPointer Time complexity O(N) space O(1)
*/

vector<vector<int> > matrix(5000, vector<int> (5000));

int knows(int a, int b)
{
      return matrix[a][b];
}
int celebStack(int n)
{
    if(n<2) return -1; // less 2 then celeb is not exist
    stack<int> st;

	for(int i=0; i<n; i++)  st.push(i); // push all elements in stack

   // pull two elements form stack
	int a = st.top();
	st.pop();
	int b = st.top();
	st.pop();

    // check until there is one element
	while(st.size()>1)
	{
		if(knows(a, b))    //  b is celeb 
		   a = st.top(), st.pop();
	    else              //   otherwise case
		   b = st.top(), st.pop();
	}
 
    int c= st.top();   // not exmine elements are left so check them celeb or not
	if(knows(c, a))  c= a;
	if(knows(c, b))  c= b;

	for(int i=0; i< n; i++)
	{
		 if(i!=c && (knows(c, i) || !knows(i, c)))  // check c last one is celeb or not
		 return -1;

	}
	return c;
}
 
int celebTwoPoiner(int n)
{
    if(n<2) return -1; // less 2 then celeb is not exist

    int s =0, e=n-1;  // s = start, e = end

	while(s < e)
	{
		if(knows(s, e))   // e is celeb then 
		    s++;
	    else              // otherwise 
		    e--;
	}

	for(int i=0; i< n; i++)
	{
		 if(i!=s && (knows(s, i) || !knows(i, s)))
		 return -1;

	}
	return s;
}

int main()
{
	int n;   cin>>n;

	for(int i=0; i< n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>matrix[i][j];
			//cout<<matrix[i][j]<<" ";
		}
		//cout<<"\n";
	}
    int id = celebTwoPoiner(n);
    //int id = celebStack(n);
	cout<<((id==-1)?"Celeb is Not Here!!":"Celeb is Here:"+to_string(id))<<"\n";

}
