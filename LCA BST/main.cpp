#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include"Binary.cpp"
using namespace std;

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
}

int getLCA(BinaryTreeNode<int> *root,int n1,int n2){

    if(root == NULL){
        return -1;
    }
    if(root->data == n1 || root->data == n2){
        return root->data;
    }
    int small1,small2;
    if(root->data < n1 && root->data <n2 ) {
        small2 = getLCA(root->right,n1,n2);
        if(small2 != -1){
        return small2;
        }
        else {
          return -1;
         }
    }
    else if(root->data > n1 && root->data >n2){
        small1 = getLCA(root->left,n1,n2);

        if(small1 != -1){
        return small1;
        }
        else {
          return -1;
         }
    }


}

int main()
{
   BinaryTreeNode<int> *root = takeinput();
   int sum;
   cout<<"Number : ";
   cin>>sum;
   pairSum(root,sum);
   return 0;
}
