#include <iostream>
#include <list> 
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<pair<long long, long long>> vec;

struct Node {
	long long  data;
	Node* left;
	Node* right;
	int h; // высота
	int l; // число способов
	int msl = 0; //длина полупути
	int a = 0, b = 0;

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
	
	vec.push_back(make_pair(tree->data, (tree->a + tree->b)));

	if (tree->left) preOrder(tree->left);
	if (tree->right) preOrder(tree->right);
}

Node* findMin(Node* node) {
	if (node->left != NULL) {
		return findMin(node->left);
	}
	else
		return node;
}

Node* removeNode(Node* node, long long key)
{
	if (node == NULL)
		return NULL;
	if (key < node->data) {
		node->left = removeNode(node->left, key);
		return node;
	}
	if (key > node->data) {
		node->right = removeNode(node->right, key);
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
		node->right = removeNode(node->right, min);
		return node;
	}
}

vector<int> v;
int maxMsl;

void markB(Node* node) {
	if (node->right == NULL && node->left == NULL) {
		node->b = 0;
		return;
	}
	if (node->left) markB(node->left);
	if (node->right) markB(node->right);
	if (node->msl == maxMsl) {
		node->b = 1;
		if (node->left) node->b = (node->left)->l;
		if (node->right) node->b *= (node->right)->l;
	}
	else {
		node->b = 0;
	}
}

void step1(Node* node) {

	if (node->left == node->right && node->left == NULL) {
		node->h = 0;
		node->l = 1;
		node->msl = 0;
		v.push_back(node->msl);
		return;
	}
	if (node->left != NULL) {
		step1(node->left);
	}
	if (node->right != NULL) {
		step1(node->right);
	}

	if (node->right == NULL) {
		node->h = ((node->left)->h) + 1;
		node->l = (node->left)->l;
		node->msl = (node->left)->h + 1;
	}
	else
		if (node->left == NULL) {
			node->h = ((node->right)->h) + 1;
			node->l = (node->right)->l;
			node->msl = (node->right)->h + 1;
		}
		else
			if (node->left->h > node->right->h) {
				node->h = (node->left)->h + 1;
				node->l = (node->left)->l;
				node->msl = (node->right)->h + (node->left)->h + 2;
			}
			else
				if (node->left->h < node->right->h) {
					node->h = (node->right)->h + 1;
					node->l = (node->right)->l;
					node->msl = (node->right)->h + (node->left)->h + 2;
				}
				else
					if (node->left->h == node->right->h) {
						node->h = (node->right)->h + 1;
						node->l = (node->right)->l + (node->left)->l;
						node->msl = (node->right)->h + (node->left)->h + 2;
					}
	v.push_back(node->msl);
}

void step2(Node* node) {
	if (node->left == node->right && node->left == NULL) {
		return;
	}

	if (node->right == NULL) {
		(node->left)->a = node->a + node->b;
	}
	else
		if (node->left == NULL) {
			(node->right)->a = node->a + node->b;
		}
		else
			if ((node->left)->h > (node->right)->h) {
				(node->left)->a = node->a + node->b;
				(node->right)->a = node->b;
			}
			else
				if ((node->left)->h < (node->right)->h) {
					(node->left)->a = node->b;
					(node->right)->a = node->a + node->b;
				}
				else
					if ((node->left)->h == (node->right)->h) {
						(node->left)->a = node->b + ((node->left)->l * ((node->a) / (node->l)));
						(node->right)->a = node->b + ((node->right)->l * ((node->a) / (node->l)));
					}
	if (node->left != NULL) {
		step2(node->left);
	}
	if (node->right != NULL) {
		step2(node->right);
	}

}
int main() {

	Node* BinTree = NULL;
	typedef istream_iterator<long long> input;
	list<long long> l((input(fin)), input());

	for (auto it = l.begin(); it != l.end(); it++) {
		createTree(*it, BinTree);
	}

	BinTree = removeNode(BinTree, BinTree->data);
	step1(BinTree);
	maxMsl = *max_element(v.begin(), v.end());
	markB(BinTree);
	step2(BinTree);
	preOrder(BinTree);

	for (int i = 0; i < vec.size(); i++) {
		if (vec.size() == 1) {
			fout << vec[i].first << ' ' << 1 << endl;
		}
		else
			fout << vec[i].first << ' ' << vec[i].second << endl;
	}
	return 0;
}