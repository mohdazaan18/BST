#include <iostream>
#include<queue>

#include<algorithm>
#include<vector>
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


void sortt(BinaryTreeNode<int> *root,vector<int> &arr){
    if(root == NULL){
        return;
    }

    arr.push_back(root->data);
    sortt(root->left,arr);
    sortt(root->right,arr);
}




void pairSum(BinaryTreeNode<int> *root,int sum){
    vector<int> arr;
    sortt(root,arr);
    sort(arr.begin(),arr.end());
    int i = 0;
    int j = arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j] == sum){
            cout<<arr[i]<<" "<<arr[j]<<" "<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] > sum){
            j--;
        }
        else if(arr[i]+arr[j]<sum){
            i++;
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
