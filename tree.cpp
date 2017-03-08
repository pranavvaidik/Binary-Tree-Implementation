#include <iostream>
using namespace std;

struct node{
	int value;
	struct node *leftChild = NULL;
	struct node *rightChild = NULL;
}


class tree
{
public:
	void insert_node(int node_key);
	node *search(int node_key);

private:
	void *search(int node_key, node *leaf);
	void *node_key(int node_key, node *leaf);
	node *root;
}

tree::tree()
{
	root = NULL;
}


tree::~tree()
{
}

void tree::insert_node(int node_key, node *leaf)
{
	if(node_key < leaf->key_value)
	{
		if(leaf->leftChild != NULL) 
			insert(node_key, leaf->leftChild);
		else
		{
			leaf->leftChild = new node;
			leaf->leftChild->key_value = node_key;
			//left->left->left = NULL;
			//left->left->right = NULL;
		}
	}

	else if(node_key < leaf->key_value)
	{
		if(leaf->rightChild != NULL) 
			insert(node_key, leaf->rightChild);
		else
		{
			leaf->rightChild = new node;
			leaf->rightChild->key_value = node_key;
			//left->right->left = NULL;
			//left->right->right = NULL;
		}
	}
}

void tree::insert_node(int node_key)
{
	if (root != NULL)
		insert(node_key, root)
	else
	{
		root = new node;
		root->key_value = key;
		//root->left = NULL;
	}
}



