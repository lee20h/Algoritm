#include "cNode.h"
#include <iostream>
using namespace std;
 
template <typename T>
class cBinarySearchTree{
friend class cNode<T>;
public:
    cBinarySearchTree();
    ~cBinarySearchTree();
    void treeInsert(T x);
    void treeDelete(T x);
    void treePrint();
private:
    cNode<T>* treeInsert(cNode<T>* t, T x);
    void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);   
    cNode<T>* deleteNode(cNode<T>* r);
    void treePrint(cNode<T>* t, int step);
    cNode<T>* root;
};

template <typename T>
cBinarySearchTree<T>::cBinarySearchTree(){
	root = NULL;
}
template <typename T>
cBinarySearchTree<T>::~cBinarySearchTree() {}


template <typename T>
void cBinarySearchTree<T>::treeInsert(T x){
    root = treeInsert(root, x);
}

template <typename T>
cNode<T>* cBinarySearchTree<T>::treeInsert(cNode<T>* n, T x) {
	cNode<T>* new_node = new cNode<T>();
	if(n == NULL) {
	    new_node->key = x;
		new_node->left = NULL;
		new_node->right = NULL;
	    return new_node;
	}
   if(x < n->key)  {
		n->left = treeInsert(n->left, x); 
		return n;
   }
   else {
		n->right = treeInsert(n->right, x);
		return n;
   }
}

template <typename T>
void cBinarySearchTree<T>::treeDelete(T x){
    cNode<T>* r = root;
    cNode<T>* p = 0;
	while (r != NULL && r->key != x) { // r의 부모를 찾아 p에 저장
		p = r;
		if (x < r->key) r = r->left;
		else if (x > r->key) r = r->right;
	}
    if(r) treeDelete(root, r, p);
}

template <typename T>
void cBinarySearchTree<T>::treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p) {
	if (r == t) {
		root = deleteNode(t);
	}
	else if (r == p->left) {
		p->left = deleteNode(r);
	}
	else {
		p->right = deleteNode(r);
	}
}
template <typename T>
cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* r) {
	if (r == NULL)
		return NULL;

	if (r->left == NULL && r->right == NULL) {
		return NULL;
	}
	else if (r->left == NULL && r->right != NULL) {
		return r->right;
	}
	else if (r->left != NULL && r->right == NULL) {
		return r->left;
	}
	else {
		cNode<T>* subNode = r->right;
		cNode<T>* parentNode = NULL;
		while (subNode->left != NULL) {
			parentNode = subNode;
			subNode = subNode->left;
		}
		r->key = subNode->key;
		if (subNode == r->right) {
			r->right = subNode->right;
		}
		else {
			parentNode->left = subNode->right;
		}
		return r;
	}
}

template <typename T>
void cBinarySearchTree<T>::treePrint() {
	treePrint(root, 0);
}

template <typename T>
void cBinarySearchTree<T>::treePrint(cNode<T>* t, int step) {
	if (t==NULL) return;
	for (int i = 0; i < step * 4; i++) {
		cout << " ";
	}
	cout << t->key << '\n';
	if ((t->left != NULL) && (t->right != NULL)) {
		treePrint(t->left, ++step);
		treePrint(t->right, step);
	}
	else if (t->left != NULL && t->right == NULL) {
		treePrint(t->left, ++step);
	}
	else if (t->left == NULL && t->right != NULL) {
		treePrint(t->right, ++step);
	}
}

