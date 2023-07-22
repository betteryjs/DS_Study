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
    int res = 0;
    int deep = 0;
public:
    int maxDepth(TreeNode *root) {
        traverse(root);
        return res;


    }

    void traverse(TreeNode *root) {
        if (root == nullptr) {
            res = max(res, deep);
            return;
        }
        deep++;
        traverse(root->left);
        traverse(root->right);
        deep--;


    }
};

class Solution2 {


public:


    int maxDepth(TreeNode *root) {

        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        // 整棵树的最大深度等于左右子树的最大深度取最大值，
        // 然后再加上根节点自己
        int res = max(leftMax, rightMax) + 1;
        return res;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
()