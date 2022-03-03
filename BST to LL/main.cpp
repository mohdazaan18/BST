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
template <typename T>
class Node{
  public :
  T data;
  Node<T> *next;

  Node(T data){
      this->data = data;
      next =NULL;
  }
};

class LLhelper{
  public :
  Node<int> *head;
  Node<int> *tail;

  LLhelper(){
      head = NULL;
      tail = NULL;
  }

};

LLhelper contructLLfromtree(BinaryTreeNode<int> *root){
    if(root == NULL){
        LLhelper case1;
        return case1;
    }

    LLhelper linfo = contructLLfromtree(root->left);
    LLhelper rinfo = contructLLfromtree(root->right);

    Node<int> *newNode = new Node<int>(root->data);
    LLhelper output;

    if(linfo.head!= NULL){
        linfo.tail->next = newNode;

    }
    newNode->next = rinfo.head;
    if(linfo.head!=NULL){
        output.head = linfo.head;
    }
    else {
        output.head = newNode;
    }
    if(rinfo.head!=NULL){
    output.tail = rinfo.tail;
    }
    else{
        output.tail = newNode;
    }

    return output;



}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root){
    LLhelper answer = contructLLfromtree(root);
    return answer.head;
}

void printLL(Node<int> *head){
if(head == NULL){
    return;
}
cout<<head->data<<" ";
printLL(head->next);


}


int main()
{
   BinaryTreeNode<int> *root = takeinput();
   Node<int> *headd = constructLinkedList(root);
   printLL(headd);

    return 0;
}
