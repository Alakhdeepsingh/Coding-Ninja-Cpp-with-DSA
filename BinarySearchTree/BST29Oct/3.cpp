//Check BST 3 
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
void printTree(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchild=takeinput();
    BinaryTreeNode<int>* rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}
BinaryTreeNode<int>* search(BinaryTreeNode<int>* root, int a){
    if(root==NULL){ 
        return NULL;
    }
    if(root->data==a){
        return root;
    }
    if((root->data)<a){
        search(root->right,a);
    }
    search(root->left,a);
}
int main()
{
    BinaryTreeNode<int>* root=takeinput();
    printTree(root);
    int a;
    cin>>a;
    BinaryTreeNode<int>* d=search(root,a);
    if(d==NULL){
        cout<<"NULL"<<endl;
    }
    else{
        cout<<d->data<<endl;
    }
    return 0;
}