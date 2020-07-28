#include<bits/stdc++.h> 
using namespace std;

/*
find Lexicographically smallest subsequence of size k
Divide and conquer solution O(NlogN)
@avinashz14 
nithost16
 */

vector<int> res;
int  n, k;

//helper function for finding min value index

int minVal(vector<int> arr, int i, int j)
{
	if(i==-1) return j;
	if(j==-1) return i;
	return (arr[i]<=arr[j])?i:j;
}
//RMQUtil function for RMQ utility helper function 
// arr : given array, *st : segmenttree array , ss : segment starting
// se : segment ending, qs : query starting, qe : query ending, si: segment current index
int RMQUtil(vector<int> arr, int *st, int ss, int se, int qs, int qe, int si)
{
	if(qs <=ss && se<=qe)    // if  segment lies in query range return current st[si]
	  return st[si];

	if(qs >se || ss > qe)   // if segment is outside then  return -1 
	  return -1;

	  int mid = ss+(se-ss)/2;  // find mid of given segment range

	  return minVal(arr, RMQUtil(arr, st, ss, mid, qs, qe, si*2+1),
	                            RMQUtil(arr, st, mid+1, se, qs, qe, si*2+2) );
}

int RMQ(vector<int> arr, int *st, int n, int qs, int qe)
{
	if(qs < 0 || qe>n-1	 || qs>qe)     // if query in invalid 
	{
		cout<<"invalid\n";
		return -1;           
	}

	return RMQUtil(arr, st, 0, n-1, qs, qe, 0);// Utility function  
}

void getMaxArea(vector<int> arr, int *st, int n, int l , int r)
{
	if(l>r) return ;
	if(l==r) return ;
    l=-1,r=n-k;
	while(k--)
     {
		 l = RMQ(arr, st, n, l+1 , r++);  // find next min val in range (l,r)
		 
	     res.push_back(arr[l]);  // insert min val in range of (l, r)
	 }
}

int constUtil(vector<int> arr, int *st, int ss, int se, int si)
{
	if(ss==se) // if reach to leaf node assign 
	return st[si]=ss;
    
	int mid = ss+(se-ss)/2;

	st[si] =minVal(arr, constUtil(arr, st, ss, mid, si*2+1), 
	constUtil(arr, st, mid+1, se, si*2+2));
	return st[si]; 
}

void constSt(vector<int> arr, int n)
{
	int x = (int)(ceil(log2(n)));
	int mxx = 2*pow(2, x)-1;
	int *st = new int[mxx];
    constUtil(arr, st, 0, n-1, 0);
	getMaxArea(arr, st, n,  0, n-1);
}

void maxArea(vector<int> arr, int n)
{
	constSt(arr, n);
}
int main()
{
	cin>>n>>k;   // input size of array N and subsequence size K
	int  size_k=k;
	vector<int> arr(n);
	for(auto &i:arr) cin>>i;    // input array 
    maxArea(arr, n);
	cout<<"Lexicographically smallest subsequence:- ";  // output 
	for(int i=0; i<size_k; i++) cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}



/* 
   time complexity O(NlogN)
   space complexity O(2^log(n))
*/