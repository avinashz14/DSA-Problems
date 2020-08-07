#include<bits/stdc++.h> 
using namespace std;

/*
@avinashz14
nithost_16
Raintrappinng problem 
1. Stack solution Time O(N)
                 space O(N)
2. using twoPointer Time O(N)
                 space O(1)
*/

int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}

int trap2(vector<int>& height)
{
    int left_max=0, right_max=0;
	int left =0, right =height.size()-1;
    int ans=0;

	while(left <= right)
	{
		if(a[left] < a[right])
		{
			if(a[left] > left_max)
			left_max= a[left];
			else 
			  ans +=left_max - a[left];
			left++;
		}
		else
		{
			if(a[right] > right_max)
			    right_max= a[right];
			else 
			    ans += right_max - a[right];

			right--;
		}
	}
    return ans;
}
int main()
{
	vector<int> a= {3, 0, 2, 0, 1};
	cout<<trap(a)<<"\n";
	return 0;
}