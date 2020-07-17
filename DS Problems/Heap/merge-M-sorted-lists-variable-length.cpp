//??......LekhanKarya..Nithost_16??
//
//Time Complexity for push/pop O(log(M))   so OverAll O(Nlog(M))  Time;
//Wed May 13 12:08:46 IST 2020
//

# include "bits/stdc++.h"
using namespace std;


// A min-heap node
struct Node
{
	// val stores the element,
	// i stores list number of the element,
	// index stores column number of the list from which element was taken
	int val, i, index;
};

// Comparison object to be used to order the min-heap
struct cmp
{
     bool operator()(const Node a, const Node b)  const
     {
            return a.val > b.val ;
     }
};

// Function to merge M sorted lists of variable length and
// print them in ascending order
void mergeSort(vector<int> list[], int m)
{

     priority_queue<Node, vector<Node> , cmp> pq;

     // push first element of each list into the min-heap
	// along with list number and their index in the list
     for(int i=0; i<m ; i++)
     {
          if(list[i].size()>0)
          {
              pq.push({list[i][0], i, 0});
          }
     }

// run till min-heap is not empty
     while (!pq.empty())
     {
          // extract minimum node from the min-heap
          Node min = pq.top();
          pq.pop();

          // print the minimum element
          cout<<min.val<<" ";
          
         // take next element from "same" list and
		// insert it into the min-heap
          if(min.index + 1 < list[min.i].size())
          {
               min.index++;
               min.val= list[min.i][min.index];
               pq.push(min);
          }
          /* code */
     }
}

int main()
{
     vector<int> list[]=
    {
		{ 10, 20, 30, 40 },
		{ 15, 25, 35 },
		{ 27, 29, 37, 48, 93 },
		{ 32, 33 }
	};

     int m = sizeof(list)/ sizeof(list[0]);

     mergeSort(list, m);

     return 0;
}

// Ouput 10 15 20 25 27 29 30 32 33 35 37 40 48 93 

