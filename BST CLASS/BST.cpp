#include<iostream>
#include"Binary.cpp"
using namespace std;
class BST{
    public :
    BinaryTreeNode<int> *root;


    BST(){
        root = NULL;
    }




    void insert(int x){
        this->root = insert(this->root,x);
    }

    void remove(int x){
        root = remove(root,x);
    }
    void print(){
        print(root);
    }
    bool search(int x){
        return search(root,x);
    }

    private :
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *root,int x){
        if(root == NULL){
            BinaryTreeNode<int> *treenode = new BinaryTreeNode<int>(x);
            return treenode;
        }

        if(root->data >= x){
            root->left = insert(root->left,x);

        }
        else if(root->data < x){
            root->right = insert(root->right,x);

        }

        return root;
    }

    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *root,int x){
        if(root == NULL){
            return NULL;
        }
        if(root->data > x){
            root->left = remove(root->left,x);
            return root;
        }
        else if(root->data < x ){
            root->right = remove(root->right,x);
            return root;
        }
        else {
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->right== NULL){
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if(root->left==NULL){
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else {
              BinaryTreeNode<int> *node = root->right;
              while(node->left!=NULL){
                  node = node->left;
              }
                int mindata = node->data;
                root->data = mindata;
                root->right = remove(root->right,mindata);
                return root;

            }
        }
    }

    void print(BinaryTreeNode<int> *root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left !=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right != NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        print(root->left);
        print(root->right);

    }

    bool search(BinaryTreeNode<int> *root,int x){
        if(root==NULL){
            return false;
        }
        if(root->data == x){
            return true;
        }

        if(root->data>x){
            bool small = search(root->left,x);
            return small;
        }
        else if(root->data < x){
          bool small = search(root->right,x);
         return small;
        }

    }


};
