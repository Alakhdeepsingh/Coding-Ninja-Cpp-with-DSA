#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode{
    public:
    vector<TreeNode<T>*>children;
    T data;
TreeNode(T data){
this->data=data;
}
};
int main()
{
    TreeNode<int>* node1 = new TreeNode<int>(1);
    TreeNode<int>* node2 = new TreeNode<int>(2);
    TreeNode<int>* root = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    return 0;
}


