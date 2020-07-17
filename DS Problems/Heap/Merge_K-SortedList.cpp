
/*
Author @avinashz14
Merge KSortedList in one
Case 1:  if k list are in ascending order
Case 2:  if k list are in descending order
*/

# include "bits/stdc++.h"
using namespace std;
// A linked list node
struct Node
{
     int key;
     Node* next;

     Node(int key)
     {
         this->key= key;
         this->next=nullptr;
     }
};

// Utility function to print contents of a linked list
void printNode(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->key<<"->";
        head=head->next;
    }
    cout<<"nullptr\n";

}

// Comparison object to be used to order the min-heap
struct cmp
{
    bool operator()(const Node* a, const Node* b)const
    {
        return a->key > b->key;    // for descending order case operator a->key < b->key 
    }
};


// The main function to merge given k sorted linked lists
// It takes an array of lists list[0..k) and generates the sorted output
Node*  mergeKlist(Node* list[], int k)
{
    // create an empty min-heap
    priority_queue<Node*, vector<Node*> , cmp> pq;

    // push first node of each list into the min-heap
    for(int i=0;i< k; i++)
    {
        pq.push(list[i]);
    }
     
    // take two pointers head and tail where head points to the first node
	// of the output list and tail points to its last node
    Node *head=nullptr, *tail=nullptr;

    // run till min-heap is not empty
    while(!pq.empty())
    {
        // extract minimum node from the min-heap
        Node *min= pq.top();
        pq.pop();

        // add the minimum node to the output list
        if(head == nullptr)
        {
            head= tail= min;
        }
        else 
        {
            tail->next= min;
            tail= min;
        }
        
        // take next node from "same" list and insert it into the min-heap
        if(min->next!=nullptr)
        {
            pq.push(min->next);
        }
    }
    // return head node of the merged list
   return head;
}

int main()
{
    int k=3; // Number of linked lists
    Node* list[k]; // An array to store the head nodes of the linked lists

/// Case 1:  
    list[0]= new Node(1);
    list[0]->next= new Node(5);
    list[0]->next->next= new Node(7);
    // list1= 1->5->7

    list[1]=new Node(2);
    list[1]->next= new Node(3);
    list[1]->next->next= new Node(6);
    list[1]->next->next->next= new Node(9);
    // list2= 2->3->6->9

    list[2]= new Node(4);
    list[2]->next= new Node(8);
    list[2]->next->next= new Node(10);
    // list3 = 4->8->10

/// Case 2:
   /*
    list[0]= new Node(7);
    list[0]->next= new Node(5);
    list[0]->next->next= new Node(1);
    // list1= 7->5->1

    list[1]=new Node(9);
    list[1]->next= new Node(6);
    list[1]->next->next= new Node(3);
    list[1]->next->next->next= new Node(2);
    // list2= 9->6->3->2

    list[2]= new Node(10);
    list[2]->next= new Node(8);
    list[2]->next->next= new Node(4);
    // list3 = 10->8->4

     //Output list = 10->9->8->7->6->5->4->3->2->1->nullptr for descending order
   */

    // Merge all lists into one
    Node* head = mergeKlist(list, k);
    printNode(head);
    //Output list = 1->2->3->4->5->6->7->8->9->10->nullptr  for ascending order
    return 0;

}

//Complexity minHeap = O(log(K))  for push/pop 
//Overall Complexity = O(Nlog(K))
//Space Comlexity = O(K)