
//Add two numbers represented by linked lists head points to LSD (least significent digit)
#include "bits/stdc++.h"
using namespace std;

class Node
{
   public:
   int data;
   Node* next;

   Node()
   {
       data =0;
       this->next = NULL;
   }
   
   Node(int d)
   {
       data = d;
       this->next = NULL;
   }
};

int findLength(Node *head)
{
    int cnt=0;
    Node* cur = head;
    while(cur!=NULL)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}
void display(Node* head)
{
      if(head==NULL) return ;

      Node* cur = head;
      while(cur!=NULL)
      {
          cout<<cur->data<<" ";
          cur = cur->next;
      }
}

void swapPointer(Node** a, Node** b)
{
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node** res, int data)
{
        Node* n = new Node(data);
        n->next = (*res);
        (*res) = n;
}

Node* addSameSize (Node* h1, Node* h2, int* carry)
{
     if(h1==NULL) 
       return NULL;
     
     Node* res =new Node();
     res->next=  addSameSize(h1->next, h2->next, carry);
     
     int sum=0;
     sum = h1->data + h2->data + *carry;
     *carry = sum/10;
     sum= sum%10;
     res->data = sum;
     return res;
}

void addRemaining(Node* h1, Node* cur, int* carry , Node** res)
{
     int sum;
     if(h1!=cur) // If diff. number of nodes are not traversed, add carry  
     {
        addRemaining(h1->next, cur, carry, res);
        sum = h1->data + *carry;
        *carry = sum/10;
        sum= sum%10;
        push(res, sum);// add this node to the front of the result  
     }
}

void addlist(Node* list1, Node* list2, Node** res)
{
    
    //find the length of both lists
   int l1 = findLength(list1);
   int l2 = findLength(list2);
   if(list1==NULL) {  //if list1 is NULL list then res will be list2
       *res=list2;
       return ;
   }
   else if(list2==NULL) //if list2 is NULL list then res will be list1
   {
       *res=list1;
       return ;
   }
   int carry=0;
   if(l1==l2)  // if both the lists are same size then call  this function 
   {
      *res = addSameSize(list1, list2, &carry);
   }
   else // if both the lists are not same size then call this function  for small size and then for remaining size 
   {       
            int l3 = abs(l1-l2);
            
            if(l1 < l2)
            swapPointer(&list1, &list2);  //make sure list1 is larger always 

            Node* cur= list1;

            while(l3--) cur = cur->next;    // move diff. number of nodes in first list 
            *res= addSameSize(cur, list2, &carry); // get addition of same size lists 
            addRemaining(list1, cur, &carry, res);       // get addition of remaining first list and carry      
   }  
   if(carry)
   push(res,carry);
}

int main() 
{ 
	Node *head1 = NULL, *head2 = NULL, *result = NULL; 

	int arr1[] = {9, 9, 9}; 
	int arr2[] = {1, 8}; 

	int size1 = sizeof(arr1) / sizeof(arr1[0]); 
	int size2 = sizeof(arr2) / sizeof(arr2[0]); 

	// Create first list as 9->9->9 
	int i; 
	for (i = size1-1; i >= 0; --i) 
		push(&head1, arr1[i]); 

	// Create second list as 1->8 
	for (i = size2-1; i >= 0; --i) 
		push(&head2, arr2[i]); 
    Node* res;
	addlist(head1, head2, &res); // call addlist for adding list
    display(res); //Display the result list

	return 0; 
} 

