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


// 后序遍历（DFS） 深度优先搜索
class Solution {
public:
    int maxDepth(TreeNode *root) {

        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return max(leftMax, rightMax) + 1;

    }
};

// 层序遍历（BFS）队列

class Solution2 {
public:
    int maxDepth(TreeNode *root) {

        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        int ans = 0;
        while (!queue.empty()) {
            int sz = queue.size();
            while (sz > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
                sz--;
            }
            ans++;


        }
        return ans;

    }
};

