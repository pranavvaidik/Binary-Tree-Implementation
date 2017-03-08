#include <iostream>
using namespace std;

struct node{
	int value;
	struct node *leftChild;
	struct node *rightChild;
};


class tree
{
public:
	tree();
	~tree();	
	
	void insert_node(int node_key);
	node *search(int node_key);
	void preOrder();
	int height();

private:
	node *search(int node_key, node *leaf);
	void insert_node(int node_key, node *leaf);
	int height(node *n);
	void preOrder(node *n);	
	node *root;

};

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
			insert_node(node_key, leaf->leftChild);
		else
		{
			leaf->leftChild = new node;
			leaf->leftChild->value = node_key;
			leaf->leftChild->leftChild = NULL;
			leaf->leftChild->rightChild = NULL;
			//cout << "the left node value of "<< node_key << " was inserted successfully" << endl;
		}
	}

	else if(node_key > leaf->value)
	{
		if(leaf->rightChild != NULL) 
			insert_node(node_key, leaf->rightChild);
		else
		{
			leaf->rightChild = new node;
			leaf->rightChild->value = node_key;
			leaf->rightChild->leftChild = NULL;
			leaf->rightChild->rightChild = NULL;
			//cout << "the right node value of "<< node_key << " was inserted successfully" << endl;
		}
	}
}

void tree::insert_node(int node_key)
{
	if (root != NULL)
		insert_node(node_key, root);
	else
	{
		root = new node;
		root->value = node_key;
		root->leftChild = NULL;
		root->rightChild = NULL;
		
	}
}

node *tree::search(int node_key, node *leaf)
{
	if(leaf!=NULL)
	{
		if(node_key == leaf->value)
			return leaf;
		else if(node_key < leaf->value)
			return search(node_key,leaf->leftChild);
		else return search(node_key,leaf->rightChild);
	}
	else return NULL;
}

node *tree::search(int node_key)
{
	return search(node_key, root);
}

void tree::preOrder(node *n)
{
	if (n != NULL)
	{
		cout << n->value << ", "<<endl;
		preOrder(n->leftChild);
		//cout << "printed a value" << endl;
		preOrder(n->rightChild);
	}
	else 
	{
		//cout << "some problem";
		return;
	}
}

void tree::preOrder()
{
	return preOrder(root);
}

int tree::height(node *n)
{
	if (n==NULL)
		return 0;
	else
	{
		int leftHeight = height(n->leftChild);
		int rightHeight = height(n->rightChild);
		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else return rightHeight + 1;
	}
}

int tree::height()
{
	return height(root);
}

int main()
{
	tree binaryTree;

	//inserting some values into the binary tree
	binaryTree.insert_node(10);
	binaryTree.insert_node(6);
	binaryTree.insert_node(14);
	binaryTree.insert_node(5);
	binaryTree.insert_node(8);
	binaryTree.insert_node(11);
	binaryTree.insert_node(18);

	//pre-order traversal
	binaryTree.preOrder();

	//search
	node *n = binaryTree.search(14);
	cout <<"node value is "<< n->value <<endl;
	cout <<"with left child " << n->leftChild->value <<" and with right child " << n->rightChild->value << endl;


	//height
	cout << "height of this tree is " << binaryTree.height() << endl;
	binaryTree.insert_node(12);
	cout << "height of this tree after insertion of new node is " << binaryTree.height() << endl;










}
