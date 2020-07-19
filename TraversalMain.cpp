#include<iostream>
#include"tree.h"
using namespace std;


//---------------------------MAIN--------------------------------------------------
int main() {
	tnode<int> *n1 = new tnode<int>(3);
	tnode<int> *n2 = new tnode<int>(-1);
	tnode<int> *n3 = new tnode<int>(8, n2, n1);
	tnode<int> *n4 = new tnode<int>(4);
	tnode<int> *n5 = new tnode<int>(6, n3, n4);
	tnode<int> *n6 = new tnode<int>(7);
	tnode<int> *n7 = new tnode<int>(8,n5,n6);
	
	


	cout << "\npreorder: ";
	n7->preorder();
	cout << "\ninorder: ";
	n7->inorder();
	cout << "\npostorder: ";
	n7->postorder();
	cout << "\n";

	cout << "height = " << n7->depth() << endl;
	cout << "is Perfect ? " << n7->isPerfect() << endl;
	cout << "is Complete ? " << n7->isComplete() << endl;
	cout << "num os leaves is: " << n7->countLeaves() << endl;
	cout << "there are " << n7->countInternalNodes() << " internal nodes" << endl;
	cout << n7->isHeightBalance() << endl;
	getchar();

	return 0;
} //main



