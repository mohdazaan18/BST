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

vector<int> *getpath(BinaryTreeNode<int> *root,int x){
    if(root == NULL){
        return NULL;
    }


    if(root->data == x){
     vector<int> *out = new vector<int>();
     out->push_back(root->data);
     return out;
    }

    vector<int> *output = new vector<int>();
    if(root->data > x){
        vector<int> *small = getpath(root->left,x);
        if(small!=NULL){
            small->push_back(root->data);
            return small;
        }
    }
    else {
        vector<int> *small = getpath(root->right,x);
        if(small!=NULL){
            small->push_back(root->data);
            return small;
        }
    }




}



int main()
{
   BinaryTreeNode<int> *root = takeinput();
   Node<int> *headd = constructLinkedList(root);
   printLL(headd);

    return 0;
}
