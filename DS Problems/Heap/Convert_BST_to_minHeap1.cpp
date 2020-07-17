#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
using namespace std;
//Case 1: BST is Complete Binary tree 
// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node and return it
	if (root == nullptr)
		return newNode(key);

	// if given key is less than the root node, recur for left subtree
	if (key < root->key)
		root->left = insert(root->left, key);

	// if given key is more than the root node, recur for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}

// Helper function to perform level order traversal of binary tree
void printLevelOrderTraversal(Node *root)
{
	// base case: empty tree
	if (root == nullptr)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		int n = q.size();
		while (n--)
		{
			Node* front = q.front();
			q.pop();

			cout << front->key << ' ';

			if (front->left)
				q.push(front->left);

			if (front->right)
				q.push(front->right);
		}

		cout << '\n';
	}
}

// Function to perform inorder traversal of a binary tree and
// push all nodes in a queue (in encountered order)
void inorder(Node *root, queue<int> &keys)
{
	if (root == NULL)
		return;

	inorder(root->left, keys);
	keys.push(root->key);
	inorder(root->right, keys);
}

// Function to perform preorder traversal of the binary tree
// Assign each encountered node with next key from the queue
void preorder(Node *root, queue<int> &keys)
{
	// base case: empty tree
	if (root == nullptr)
		return;

	// replace root's key value with next key from the queue
	root->key = keys.front();
	keys.pop();

	// process left subtree
	preorder(root->left, keys);

	// process right subtree
	preorder(root->right, keys);
}

// Function to convert a BST to a min heap
void convert(Node *root)
{
	// maintain a queue to store inorder traversal of the tree
	queue<int> keys;
	
	// fill the queue in inorder fashion
	inorder(root, keys);

	// traverse tree in preorder fashion and for each encountered node,
	// dequeue a key from the queue and assign it to the node
	preorder(root, keys);
}

// main function
int main()
{
	Node* root = nullptr;

	/* Construct below bst
               5
             /   \
            /     \
           3       8
          / \     / \
         /   \   /   \
        2     4 6    10
	*/

	vector<int> keys = { 5, 3, 2, 4, 8, 6, 10 };
	for (int key: keys)
		root = insert(root, key);

	convert(root);
	printLevelOrderTraversal(root);

	return 0;
}