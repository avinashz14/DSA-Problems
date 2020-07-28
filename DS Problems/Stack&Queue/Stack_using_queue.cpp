#include<bits/stdc++.h> 
using namespace std;

class Stack{
	queue<int> q1, q2;
	int cur_size;

	public:
	Stack()
	{
		cur_size=0;
	}
	void Push(int x)
	{
		q2.push(x);
		cur_size++;
	}
	void Pop()
	{
		if(q2.empty())
		  return ;
	    while(q2.size()!=1) 
		{
			q1.push(q2.front());
			q2.pop();
		}
		q2.pop();
		queue<int> q= q2;
		q2 = q1;
		q1= q;
        cur_size--;
	}
	int Top()
	{
		if(q2.empty())
		return -1;
		while(q2.size()!=1)
		{
			q1.push(q2.front());
			q2.pop();
		}
		int  temp = q2.front();
		q1.push(temp);

		q2.pop();

		queue<int> q = q1;
		q1 = q2;
		q2= q;
		return temp;
	}
	int Size()
	{
		return cur_size;
	}
};

int main()
{
	Stack s;
	s.Push(9);
	s.Push(10);
	s.Push(14);
	s.Push(4);

    while(s.Size())
	{
    	cout<<s.Top()<<" ";
		s.Pop();
	}


}