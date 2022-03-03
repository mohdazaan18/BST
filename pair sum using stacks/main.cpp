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

#include<stack>

int countofnodes(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }


    int small1 = countofnodes(root->left);
    int small2 = countofnodes(root->right);

    return small1+small2+1;


}

void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {

    if(root == NULL){
        return;
    }
stack<BinaryTreeNode<int>*> s1;
stack<BinaryTreeNode<int>*> s2;
BinaryTreeNode<int> *temp = root;
while(temp!=NULL){
    s1.push(temp);
    temp = temp->left;
}
    temp = root;
while(temp!=NULL){
    s2.push(temp);
    temp = temp->right;
}
    int count = countofnodes(root);
    int c = 0;
while(c < count-1){
    if(s1.top()->data + s2.top()->data == sum){
        cout<<s1.top()->data<<" "<<s2.top()->data<<endl;
        BinaryTreeNode<int> *topin = s1.top();
        s1.pop();
        c++;
        if(topin->right!=NULL){
            topin = topin->right;
            while(topin!=NULL){
                s1.push(topin);
                topin = topin->left;
            }
        }

        BinaryTreeNode<int> *revin = s2.top();
        s2.pop();
        c++;
        if(revin->left!=NULL){
            revin = revin->left;
            while(revin!=NULL){
                s2.push(revin);
                revin = revin->right;
            }
        }

    }
    else if(s1.top()->data + s2.top()->data > sum){
        BinaryTreeNode<int> *topp = s2.top();
        s2.pop();
        c++;
        if(topp->left!=NULL){
            topp = topp->left;
            while(topp!=NULL){
                s2.push(topp);
                topp = topp->right;
            }
        }

    }
    else {
        BinaryTreeNode<int> *top = s1.top();
        s1.pop();
        c++;
        if(top->right!=NULL){
            top = top->right;
            while(top!=NULL){
                s1.push(top);
                top = top->left;
            }
        }


    }




}





}



int main()
{

    BinaryTreeNode<int> *root = takeinput();

    return 0;
}
