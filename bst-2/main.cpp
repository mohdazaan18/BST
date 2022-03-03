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

class BSThelper{
  public :
  int maximum;
  int minimun;
  bool bst;
};

BSThelper isbsthelp(BinaryTreeNode<int> *root){
    if(root == NULL){
        BSThelper case1;
        case1.maximum = INT_MIN;
        case1.minimun = INT_MAX;
        case1.bst = true;
        return case1;

    }

    BSThelper smallans1 = isbsthelp(root->left);
    BSThelper smallans2 = isbsthelp(root->right);

    int maximl = max(root->data,max(smallans1.maximum,smallans2.maximum));
    int minimr = min(root->data,min(smallans1.minimun,smallans2.minimun));

    BSThelper finalans;
    finalans.maximum = maximl;
    finalans.minimun = minimr;

    bool finalb = (root->data > smallans1.maximum) && (root->data <= smallans2.minimun) && smallans1.bst && smallans2.bst ;
    finalans.bst = finalb;
    return finalans;

}
bool isbst(BinaryTreeNode<int> *root){
    BSThelper fn = isbsthelp(root);
    return fn.bst;
}






int main()
{
   BinaryTreeNode<int> *root = takeinput();
  bool answer = isbst(root);
  if(!answer){
      cout<<"false";
  }
  else {
      cout<<"true";
  }
    return 0;
}
