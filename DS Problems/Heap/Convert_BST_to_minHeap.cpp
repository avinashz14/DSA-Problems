#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Helper function to create a new binary tree node having given key
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

// Function to construct a complete binary tree from sorted keys in the queue
Node* construct(queue<int> &keys)
{
	// construct a queue to store the parent nodes
	queue<Node*> q;

	// initialize root node of the complete binary tree
	Node* root = newNode(keys.front());
	keys.pop();

	// add root node to the queue
	q.push(root);

	// loop till all keys are processed
	while (!keys.empty())
	{
		// Dequeue front node from the queue
		Node* parent = q.front();
		q.pop();

		// allocate left child of the parent node with next key
		parent->left = newNode(keys.front());
		keys.pop();

		// add left child node to the queue
		q.push(parent->left);

		// if next key is exists
		if (!keys.empty())
		{
			// allocate right child of the parent node with next key
			parent->right = newNode(keys.front());
			keys.pop();

			// add right child node to the queue
			q.push(parent->right);

		}
	}

	// return the root node of complete binary tree
	return root;
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

// Function to convert a BST into a min heap without using
// any auxiliary space
void convert(Node* &root)
{
	// maintain a queue to store inorder traversal of the tree
	queue<int> keys;

	// fill the queue in inorder fashion
	inorder(root, keys);

	// construct a complete binary tree from sorted keys in the queue
	root = construct(keys);
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
          / \       \
         /   \       \
        2     4      10
	*/

	vector<int> keys = { 5, 3, 2, 4, 8, 10 };
	for (int key: keys)
		root = insert(root, key);

	convert(root);
	printLevelOrderTraversal(root);

	return 0;
}