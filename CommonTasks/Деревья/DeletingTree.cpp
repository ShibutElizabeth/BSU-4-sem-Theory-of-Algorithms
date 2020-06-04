#include <iostream>
#include <list> 
#include <fstream>
#include <iterator>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct Node {
	long long  data;
	Node* left;
	Node* right;
};

void createTree(long long data, Node*& BinTree) {

	if (BinTree == NULL) {
		BinTree = new Node;
		BinTree->data = data;
		BinTree->left = BinTree->right = NULL;
	}
	if (data < BinTree->data) {
		if (BinTree->left != NULL) createTree(data, BinTree->left);
		else {
			BinTree->left = new Node;
			BinTree->left->left = BinTree->left->right = NULL;
			BinTree->left->data = data;
		}
	}
	if (data > BinTree->data) {
		if (BinTree->right != NULL) createTree(data, BinTree->right);
		else {
			BinTree->right = new Node;
			BinTree->right->left = BinTree->right->right = NULL;
			BinTree->right->data = data;
		}
	}
}

void preOrder(Node*& tree)
{
	if (tree == NULL)    return;

	fout << tree->data << endl;
	preOrder(tree->left);
	preOrder(tree->right);
}


Node* findMin(Node* node) {
	if (node->left != NULL) {
		return findMin(node->left);
	}
	else
		return node;
}

Node* remove(Node* node, long long key)
{
	if (node == NULL)
		return NULL;
	if (key < node->data) {
		node->left = remove(node->left, key);
		return node;
	}
	if (key > node->data) {
		node->right = remove(node->right, key);
		return node;
	}

	if (node->left == NULL)
		return node->right;
	if (node->right == NULL) 
		return node->left;

	else {
		long long min;
		min = findMin(node->right)->data;
		node->data = min;
		node->right = remove(node->right, min);
		return node;
	}
}

int main() {
	int n;
	fin >> n;

	Node* BinTree = NULL;
	typedef istream_iterator<long long> input;
	list<long long> l((input(fin)), input());

	for (auto it = l.begin(); it != l.end(); it++) {
		createTree(*it, BinTree);
	}
	BinTree = remove(BinTree, n);
	preOrder(BinTree);
	return 0;
}