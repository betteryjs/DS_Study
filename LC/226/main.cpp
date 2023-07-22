#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {

        traverse(root);
        return root;

    }

    void  traverse(TreeNode * root){
        if(root== nullptr){
            return;
        }
        swap(root->left,root->right);
        traverse(root->left);
        traverse(root->right);

    }
};


class Solution2 {
public:
    // 定义：将以 root 为根的这棵二叉树翻转，返回翻转后的二叉树的根节点
    TreeNode *invertTree(TreeNode *root) {
        if(root== nullptr){
            return nullptr;
        }
        TreeNode * left= invertTree(root->left);
        TreeNode * right= invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;





    }


};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
