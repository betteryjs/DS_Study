//
// Created by yjs on 2022/5/1.
//
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


class DOTree {

public:


    // 定义：输入一棵二叉树，返回这棵二叉树的节点总数
    int count(TreeNode*  root) {
        if (root == nullptr) {
            return 0;
        }
        int leftCount = count(root->left);
        int rightCount = count(root->right);
        // 后序位置
        printf("节点 %s 的左子树有 %d 个节点，右子树有 %d 个节点",
               *root, leftCount, rightCount);

        return leftCount + rightCount + 1;
    }








};

int main() {

    vector<int> nums{1, 22, 26, 36};
    DOTree *doTree = new DOTree();
    doTree->traverse(nums, 0);


    return 0;

}