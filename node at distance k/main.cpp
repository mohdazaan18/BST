#include <iostream>
#include<queue>
#include<climits>
using namespace std;
#include"Binary.cpp"

BinaryTreeNode<int> *takeinput(){

    cout<<"Enter data : ";
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        int leftc,rightc;
        cout<<"Enter left child of "<<front->data<<":";
        cin>>leftc;
        if(leftc!=-1){
            BinaryTreeNode<int> *leftch = new BinaryTreeNode<int>(leftc);
            q.push(leftch);
            front->left = leftch;
        }
        cout<<"Enter right child of "<<front->data<<":";
        cin>>rightc;
        if(rightc!=-1){
            BinaryTreeNode<int> *rightch = new BinaryTreeNode<int>(rightc);
            q.push(rightch);
            front->right = rightch;
        }


    }
    return root;


}

void printlevel(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front  = q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<",";
            q.push(front->left);
        }
        else {
            cout<<"L"<<-1<<",";
        }
        if(front->right !=NULL){
            cout<<"R"<<front->right->data<<endl;
            q.push(front->right);
        }
        else {
            cout<<"R"<<-1<<endl;

    }

}

void printdepthoftree(BinaryTreeNode<int> *root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data <<endl;
    }
    printdepthoftree(root->left,k-1);
    printdepthoftree(root->right,k-1);
}

int printatdistanceK(BinaryTreeNode<int> *root,int elem,int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == elem){
        printdepthoftree(root,k);
        return 0;
    }

    int leftdis = printatdistanceK(root->left,elem,k);
    if(leftdis!=-1){

        if(leftdis+1 == k){
            cout<<root->data<<endl;
        }
        else {
        printdepthoftree(root->right,k-leftdis-2);
        }
        return 1+leftdis;
    }
    int rightdis = printatdistanceK(root->right,elem,k);
    if(rightdis!=-1){

        if(rightdis+1 == k){
            cout<<root->data<<endl;
        }
        else {
        printdepthoftree(root->left,k-rightdis-2);
        }
        return 1+rightdis;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root,int elem,int k){
    printatdistanceK(root,elem,k);
}

int main()
{

    BinaryTreeNode<int> *root = takeinput();
    nodesAtDistanceK(root,3,2);
    return 0;
}
