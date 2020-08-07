#include<bits/stdc++.h> 
using namespace std;
/*
  @avinashz14
  nithsot_16
  implementation of Stack Sorting Using recursion a variant of reverse a stack problem
  time complexity O(N^2)
  space only using Recursion Stack no extra space
*/
stack<int> st;
void insert_last(int x)
{
	if(st.empty())
	st.push(x);
	else
	{
		if(st.top() < x)
		{
			int a = st.top();
			st.pop();
			insert_last(x);
			st.push(a);
		}
		else st.push(x);
	}
	
}
void reverse()
{
	if(!st.empty())
	{
		int x = st.top();
		st.pop();

		reverse();

		insert_last(x);
	}
}

int main()
{
	int n; cin>>n;
	for(int i=0; i<n; i++)
	{
		int a; cin>>a;
		st.push(a);
	}
	reverse();
    cout<<"Sorted elements: ";
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}

	return 0;
}