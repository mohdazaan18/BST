#include <iostream>
#include<queue>

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

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int x){
    if(root ==NULL ){
        return root;
    }
    if(root->data == x){
        return root;
    }
    BinaryTreeNode<int> *ans;
    if(root->data >x){
        ans = searchInBST(root->left,x);
    }
    else if(root->data <x){
        ans = searchInBST(root->right,x);
    }
    return ans;
}

int main()
{
   BinaryTreeNode<int> *root = takeinput();
   printlevel(root);
   int n;
   cout<<"Enter number to search : "<<endl;
   cin>>n;
   BinaryTreeNode<int> *answer = searchInBST(root,n);
  if(answer!=NULL){
      cout<<"true";
  }
  else {
      cout<<"false";
  }
    return 0;
}
