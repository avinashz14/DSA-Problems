#include<bits/stdc++.h> 
using namespace std;

/*
1.using RMQ O(NlogN) 
2.using Stack O(N)

*/

/*########################----RMQ---Method O(NlogN) sol ########################################

int maxVal(int x, int y, int z)
{
	return max(max(x, y), z);
}

int minVal(vector<int> hist, int i, int j)
{
	if(i==-1) return j;
	if(j==-1) return i;
	return (hist[i]<hist[j])?i:j;
}
int RMQUtil(vector<int> hist, int *st, int ss, int se, int qs, int qe, int si)
{
	if(qs <=ss && se<=qe)
	  return st[si];

	if(qs >se || ss > qe)
	  return -1;

	  int mid = ss+(se-ss)/2;

	  return minVal(hist, RMQUtil(hist, st, ss, mid, qs, qe, si*2+1),
	                            RMQUtil(hist, st, mid+1, se, qs, qe, si*2+2) );
}
int RMQ(vector<int> hist, int *st, int n, int qs, int qe)
{
	if(qs < 0 || qe>n-1	 || qs>qe)
	{
		cout<<"invalid\n";
		return -1;
	}

	return RMQUtil(hist, st, 0, n-1, qs, qe, 0);
}

int getMaxArea(vector<int> hist, int *st, int n, int l , int r)
{
	if(l>r) return INT_MIN;
	if(l==r) return hist[l];
    
	int m = RMQ(hist, st, n, l, r);

	return maxVal(getMaxArea(hist, st, n, l, m-1), getMaxArea(hist, st, n,  m+1, r), (r-l+1)*hist[m]);
}

int constUtil(vector<int> hist, int *st, int ss, int se, int si)
{
	if(ss==se)
	return st[si]=ss;
    
	int mid = ss+(se-ss)/2;

	st[si] =minVal(hist, constUtil(hist, st, ss, mid, si*2+1), constUtil(hist, st, mid+1, se, si*2+2));
	return st[si]; 
}

int constSt(vector<int> hist, int n)
{
	int x = (int)(ceil(log2(n)));
	int mxx = 2*pow(2, x)-1;
	int *st = new int[mxx];
    constUtil(hist, st, 0, n-1, 0);
	for(int i=0; i<mxx; i++)
	  cout<<hist[st[i]]<<" ";
	  cout<<"\n";
	return getMaxArea(hist, st, n,  0, n-1);
}

int maxArea(vector<int> hist, int n)
{
	return constSt(hist, n);
}



*/


int maxArea(vector<int> hist, int n)
{
	stack<int> st;
	int area =0;
	int i=0;
	for(; i< n;)
	{
         if(st.empty() || hist[st.top()]<=hist[i])
		 {
			 st.push(i++);
		 }
		 else 
		 {
			int tp = hist[st.top()];
			st.pop();
			area =max(area, (st.empty()? i :i-st.top()-1)*tp);
		 }
	}

	while(!st.empty())
		{
			int tp = hist[st.top()];
			st.pop();
			area =max(area, (st.empty()? i :i-st.top()-1)*tp);
		}

    return area;
}

int main()
{
	int n;cin>>n;
	vector<int> hist(n);
	for(auto &i:hist) cin>>i;

	cout<<maxArea(hist, n)<<"\n";
}