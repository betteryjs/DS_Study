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

    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode *root) {
        traverse(root);
        return maxDiameter;
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        // 前序遍历
        int leftMax = maxDeep(root->left);
        int rightMax = maxDeep(root->right);

        maxDiameter = max(leftMax + rightMax, maxDiameter);
        traverse(root->left);
        traverse(root->right);
    }

    // 计算一个树的最大深度
    int maxDeep(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDeep(root->left);
        int rightMax = maxDeep(root->right);
        // 加根节点
        return 1 + max(leftMax, rightMax);


    }

};


class Solution2 {

private:
    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode *root) {

        maxDeep(root);
        return maxDiameter;

    }
    int maxDeep(TreeNode * root){
        if(root== nullptr){
            return 0;
        }

        int leftMax= maxDeep(root->left);
        int rightMax= maxDeep(root->right);

        // 后序位置，顺便计算最大直径
        maxDiameter=max(leftMax+rightMax,maxDiameter);
        return 1 + max(leftMax, rightMax);







    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
