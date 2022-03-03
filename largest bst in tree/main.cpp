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

#include<iostream>
#include<climits>
class LargestClass{
  public :
  int minim;
  int maxim;
  int height;
  bool isBST;
};


LargestClass helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        LargestClass case1;
        case1.minim = INT_MAX;
        case1.maxim = INT_MIN;
        case1.height = 0;
        case1.isBST = true;
        return case1;
    }

    LargestClass small1 = helper(root->left);
    LargestClass small2 = helper(root->right);


    LargestClass output;

    if(!(small1.isBST && root->data > small1.maxim)){
        small1.isBST = false;
    }
    else if(!(small2.isBST && root->data < small2.minim)){
        small2.isBST = false;
    }

    if(!(small1.isBST) || !(small2.isBST) || root->data < small1.maxim || root->data > small2.minim){
        if(small1.height > small2.height){
            small1.isBST = false;
            return small1;
        }
        else {
           small2.isBST = false;
            return small2;
        }

    }

    output.isBST = true;
    output.minim = min(small1.minim,min(root->data,small2.minim));
    output.maxim = max(small1.maxim,max(root->data,small2.maxim));
    output.height = max(small1.height,small2.height)+1;
    return output;
}

int largestBSTSubtree(BinaryTreeNode<int> *root){
    LargestClass answer = helper(root);
    return answer.height;
}

int main()
{
   BinaryTreeNode<int> *root = takeinput();
 cout<<largestBSTSubtree(root)<<endl;
    return 0;
}
