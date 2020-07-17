#include "bits/stdc++.h"
using namespace std;

#define ll long long 

struct Node{
  
  int data;
  struct Node* next;
  struct Node* random;
  Node(int d)
  {
    data= d;
    next=nullptr;
    random=nullptr;
  }
  Node(){}
};
void traverse(Node*  head)
{

  Node* p = head;

  while (p!=nullptr)
  {
    cout<<p->data<<" ";
    p= p->next;
  }
  
}
void updateLinkedList(Node* head, unordered_map<Node*, Node*> &ump)
{
   if(ump[head]==nullptr) return ;
    
   ump[head]->random = head->random;

   updateLinkedList(head->next, ump);

}

Node* cloneLinkedList(Node* head, unordered_map<Node*, Node*> &ump)
{
    if(head==nullptr) return head;

    ump[head] = new Node(head->data);

    ump[head]->next = cloneLinkedList(head->next, ump);

    return ump[head];
  
}

Node* cloneLinkedList(Node* head)
{
  unordered_map<Node*, Node*> ump;

  cloneLinkedList(head, ump);
  
  updateLinkedList(head,ump);

  return ump[head];
}

void remedy(Node* head)
{
  /* 1. Create duplicate of each node of the original linkedlist */

  /*traverse the original linkedlist  */
	 Node* cur = head;
	 while(cur!=nullptr)
	 {
     // take pointer to the next node of the original linkedlist
		 Node* next = cur->next;

     // make a duplicate of the current node of the original list
     Node* dup = new Node(cur->data);

     // associate each duplicate node with the next child of the original list
     cur->next = dup;
     dup->next = next;
     
     //advance the cur node to next of original list
     cur = next;
	 }
  /*2. Update the random pointers in the duplicated nodes */
   cur = head;

   while(cur!=nullptr)
   {
        // if random pointer is exists for the original list , set it for clone
         if(cur->random!=nullptr)
             (cur->next)->random = (cur->random)->next;

        //advance the cur node to next of original list
          cur = (cur->next)->next;
   }

   /* 3. extract the duplicate nodes from the modified linked list */

	// construct a dummy node whose next pointer points to the head
	// of the cloned linked list

   cur = head;
   Node Dummy;
   Node* tail = &Dummy;
	// maintain a tail node for the clone

   while(cur!=nullptr)
   {
     	// take pointer to the next node in the original list
      Node* next  = (cur->next)->next;

      // extract the duplicate
      Node* dup = cur->next;

		// restore the original linked list
      tail->next = dup;
      tail = dup;

		// advance to the next node of original list
      
      cur->next = next;
      cur = next;
   }

   traverse(Dummy.next);

} 

int main()
{
  Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	head->random = head->next->next->next;
	head->next->next->random = head->next;

	cout << "Original Linked List:\n";
	traverse(head);

	Node* clone = cloneLinkedList(head);  //time complexity O(N) Space complexity O(N)  

	cout << "\nCloned Linked List:\n";
	traverse(clone);
  //remedy(head);   //time complexity O(N) Space complexity O(1)

}