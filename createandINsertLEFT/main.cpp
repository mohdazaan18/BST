#include <iostream>
using namespace std;
#include"BST.cpp"
#include<queue>

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data : ";
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int> *createandInsert(BinaryTreeNode<int> *root){
    if(root == NULL){
        return root;
    }

    BinaryTreeNode<int> *leftans = createandInsert(root->left);
    BinaryTreeNode<int> *rightans = createandInsert(root->right);
    BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(root->data);

    root->left = newnode;
    newnode->left = leftans;

    return root;
}

int main()
{
   BinaryTreeNode<int> *root = takeInputLevelWise();
   printTree(root);
   BinaryTreeNode<int> *newans = createandInsert(root);
   printTree(newans);
}
