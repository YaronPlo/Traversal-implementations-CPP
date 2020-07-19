#pragma once
#ifndef TREE_H
#define TREE_H
#include <math.h>
#include<iostream>
using namespace std;

// represents a node in a binary tree
template<class T>
class tnode {

private:
	T value;
	tnode<T> *left, *right;
public:
	//default constructor
	tnode(T v) :value(v), left(NULL), right(NULL)
	{}

	//constructor
	tnode(T v, tnode *lptr, tnode *rptr) :value(v), left(lptr), right(rptr)
	{}


	//accessors
	T getValue() { return value; }
	void setValue(T newValue) { value = newValue; }

	void setLeft(tnode *l) { left = l; }
	void setRight(tnode *r) { right = r; }

	tnode<T> *getLeft() { return left; }
	tnode<T> *getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }

	//traversal methods
	void inorder();
	void preorder();
	void postorder();

	int depth();

	bool isComplete();
	bool isPerfect();

	int countLeaves();
	int countInternalNodes();
	bool isHeightBalance();
};

template <class T>
void tnode<T>::inorder() {
	if (left != NULL)	left->inorder();
	cout << value << " ";
	if (right != NULL)right->inorder();
}

template <class T>
void tnode<T>::preorder() {
	cout << value << " ";
	if (left != NULL)	left->preorder();
	if (right != NULL) right->preorder();

}
template <class T>
void tnode<T>::postorder() {
	if (left != NULL)	left->postorder();
	if (right != NULL)right->postorder();
	cout << value << " ";
}


template <class T>
int tnode<T>::depth() {
	if (isLeaf())
		return 0;

	int lDepth = (left == NULL) ? -1 : left->depth();
	int rDepth = (right == NULL) ? -1 : right->depth();

	return (lDepth > rDepth) ? lDepth + 1 : rDepth + 1;
}

template <class T>
bool tnode<T>::isComplete() {
	int h = depth();   //class method
	if (h == 0) return true;
	if (h == 1) return !(left == NULL);
	//the depth is 2 and up:
	bool has2Sons = (!(left == NULL) && !(right == NULL));
	bool case1 = false, case2 = false;
	if (has2Sons) {
		case1 = ((left->depth() == h - 1) && left->isComplete() &&
			(right->depth() == h - 2) && right->isPerfect());

		case2 = ((left->depth() == h - 1) && left->isPerfect() &&
			(right->depth() == h - 1) && right->isComplete());

	}
	return case1 || case2;
}

template <class T>
bool tnode<T>::isPerfect() {
	int h = depth();   //class method
	if (h == 0) return true;
	if (h == 1) return  !(left == NULL) && !(right == NULL);

	return (!(left == NULL) && (left->depth() == h - 1) && left->isPerfect() &&
		!(right == NULL) && (right->depth() == h - 1) && right->isPerfect());
}

template <class T>
int tnode<T>::countLeaves()
{
	
	if (!isLeaf())//keep search for a leaf
		return right->countLeaves() + left->countLeaves();
	if (isLeaf())//found leaf
		return 1;
	else
		return 0;
}
template <class T>
int tnode<T>:: countInternalNodes() 
{

	if (!isLeaf())
		return 1 + right -> countInternalNodes() + left->countInternalNodes();

	if (isLeaf())
		return 0;
	else
		return 0;
}
template <class T>
bool tnode<T>::isHeightBalance()
{
	int leftHei = left->depth();
	int rightHei = right->depth();
	if (abs(leftHei - rightHei) > 1)
		return false;
	return true;

}



//--------------------------------------------------------------------------------//

template <typename T>
void deleteTree(tnode<T> *t)
{
	// postorder scan. delete left and right
	// subtrees of t and then node t
	if (t != NULL)
	{
		deleteTree(t->getLeft());
		deleteTree(t->getRight());
		delete t;
	}
}

#endif
