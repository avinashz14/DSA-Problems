//Huffman enCoding 


# include "bits/stdc++.h"
using namespace std;

struct Node
{
   char ch;
   int freq;
   Node *right, *left;
};

Node* getNode(char ch, int freq, Node* left , Node *right)
{
    Node * node = new Node();
    node->ch= ch;
    node->freq= freq;
    node->left=left;
    node->right=right;

    return node;
}

// Utility function for priority_queue comparison 
struct cmp{
   bool operator()(const Node* left, const Node* right)
   {
       return left->freq > right->freq;
   }
};

//encode the string 
void encode(Node* root, string str, 
                 unordered_map<char, string > &huffmancode)
{
       if(root==nullptr)
       return;

       if(!root->left && !root->right)
       {
           huffmancode[root->ch]=str;
       }

       encode(root->left, str + "0", huffmancode);
       encode(root->right, str + "1", huffmancode);
}

//Decode the encoded string 
void decode(Node* root , int &index, string str)
{
      if(root==nullptr)
        return;

       if(!root->left && !root->right)
       {
           cout<<root->ch;
           return ;
       }
       index++;

       if(str[index]=='0')
         decode(root->left, index, str);
       else
         decode(root->right, index, str);
}
//build huffmanTree 
void BuildHuffmanTree(string s)
{
    unordered_map<char, int> freq;

    for(auto &ch:s)
    {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, cmp> pq;
    
    for(auto &pair:freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
   // make huffman tree until queue left with 1 node
   while(pq.size()!=1)
   {
       Node* left= pq.top();
       pq.pop();
       Node* right = pq.top();
       pq.pop();

       int sum = left->freq + right->freq;

       pq.push(getNode('\0', sum , left, right));
   }

   Node* root = pq.top();

   unordered_map<char, string > huffmancode;

   encode(root, "", huffmancode);
   
   cout<<"Encoded codes are :\n";
   //print encoded codes
   for(auto &pair:huffmancode)
   {
       cout<<pair.first<<" "<<pair.second<<"\n";
   }

    cout<<"\n\nOriginal string :"<<s<<"\n\n";

    string str;
    // print encoded string
     cout<<"Encoded string: ";

    for(char ch:s)
    {
          cout<<huffmancode[ch];
        str+=huffmancode[ch];
    }

    cout<<"\n\nDecoded string :";
    // traverse the Huffman Tree again and this time
	// decode the encoded string
    int index=-1;
    while(index < (int)str.size()-2)
       decode(root, index, str);
}

int main()
{
    string text = "Huffman coding is a data compression algorithm.";
    BuildHuffmanTree(text);
    return 0;
}

/*
Output:

Encoded codes are :

c 11111
h 111100
f 11101
r 11100
t 11011
p 110101
i 1100
g 0011
l 00101
a 010
o 000
d 10011
H 00100
. 111101
s 0110
m 0111
e 110100
  101
n 1000
u 10010


Original string :Huffman coding is a data compression algorithm.

Encoded string: 00100100101110111101011101010001011111100010011110010000011101110001101010101011001101011011010101111110000111110101111001101000110011011000001000101010001010011000111001100110111111000111111101

Decoded string :Huffman coding is a data compression algorithm.
*/