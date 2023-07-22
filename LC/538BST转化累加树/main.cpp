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
private:

    // 记录累加和
    int sum=0;

public:
    TreeNode *convertBST(TreeNode *root) {
        traverse(root);
        return root;

    }


    void traverse(TreeNode*  root) {
        if (root == nullptr) return;
        // 先递归遍历右子树
        traverse(root->right);
        // 中序遍历代码位置

        sum+=root->val;
        root->val=sum;

        // 后递归遍历左子树
        traverse(root->left);
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
