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

BinaryTreeNode<int> *helper(int *arr,int start,int end){
    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int> *lefthalf = helper(arr,start,mid-1);
    BinaryTreeNode<int> *righthalf = helper(arr,mid+1,end);

    root->left = lefthalf;
    root->right = righthalf;
    return root;





}

BinaryTreeNode<int> *constructtree(int *arr,int n){
    BinaryTreeNode<int> *answer = helper(arr,0,n-1);
    return answer;
}


int main()
{
 int n;
 cin>>n;
 int arr[40];
   for(int i = 0;i<n;i++){
       cin>>arr[i];
   }
  BinaryTreeNode<int> *root = constructtree(arr,n);
  printlevel(root);
    return 0;
}
