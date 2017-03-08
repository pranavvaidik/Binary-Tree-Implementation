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
	if(node_key < leaf->value)
	{
		if(leaf->leftChild != NULL) 
			insert(node_key, leaf->leftChild);
		else
		{
			leaf->leftChild = new node;
			leaf->leftChild->value = node_key;
			//left->left->left = NULL;
			//left->left->right = NULL;
		}
	}

	else if(node_key < leaf->value)
	{
		if(leaf->rightChild != NULL) 
			insert(node_key, leaf->rightChild);
		else
		{
			leaf->rightChild = new node;
			leaf->rightChild->value = node_key;
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
		root->value = node_key;
		//root->left = NULL;
	}
}

node *tree::search(int node_key, node *leaf)
{
	if(leaf!=NULL)
	{
		if(key == leaf->value)
			return leaf;
		else if(key < leaf->value)
			return search(node_key,leaf->leftChild);
		else return search(node_key,leaf->rightChild);
	}
	else return NULL;
}

node *tree::search(int node_key)
{
	return search(key, root);
}

