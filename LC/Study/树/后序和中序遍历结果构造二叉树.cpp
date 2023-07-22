//
// Created by yjs on 2022/4/28.
//
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // 后序和中序遍历结果构造二叉树
    // inorder [左 根 右]
    // postorder [左 右 根]
private:
    vector<int> inorder;
    vector<int> postorder;
    unordered_map<int, int> index;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(0, n - 1, 0, n - 1);


    }

    TreeNode *buildTreeHelper(const int &inStart, const int &inEnd, const int &postStart, const int &postEnd) {

        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(this->postorder[postEnd]);

        int inRoot = index[root->val];

        int numLeft = inRoot - inStart;

        // inorder [左 根 右]
        // postorder [左 右 根]
        root->left = buildTreeHelper(inStart, inRoot - 1,postStart,postStart+numLeft-1);
        root->right= buildTreeHelper(inRoot+1,inEnd,postStart+numLeft,postEnd-1);
        return root;


    }
};