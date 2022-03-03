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
}
int maximum(BinaryTreeNode<int> *root){
    if(root == NULL){
        return INT_MIN;
    }
    int small1 = maximum(root->left);
    int small2 = maximum(root->right);
    return max(root->data,max(small1,small2));
}
int minimum(BinaryTreeNode<int> *root){
    if(root == NULL){
        return INT_MAX;
    }
    int small1 = minimum(root->left);
    int small2 = minimum(root->right);
    return min(root->data,min(small1,small2));
}


bool isBST1(BinaryTreeNode<int> *root){
    if(root == NULL){
        return true;
    }

    int maxl = maximum(root->left);
    int minr = minimum(root->right);
    bool answer = (root->data <maxl) && (root->data>=minr) && isBST1(root->left) && isBST1(root->right);
    return answer;





}
int main()
{
   BinaryTreeNode<int> *root = takeinput();
  bool answer = isBST1(root);
  if(!answer){
      cout<<"false";
  }
  else {
      cout<<"true";
  }
    return 0;
}
