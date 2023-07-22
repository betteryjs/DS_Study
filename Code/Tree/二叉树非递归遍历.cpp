//
// Created by yjs on 2022/4/28.
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


class DoTree {
private:
    vector<int> res;

public:


    // 非递归先序遍历二叉树 [根 左 右]
    // https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-de-qian-xu-bian-li-by-leetcode-solution/
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }


    vector<int> inorderTraversal(TreeNode *root) {

        stack<TreeNode *> stackToken;
        while (!stackToken.empty() || root != nullptr) {
            while (root != nullptr) {
                stackToken.push(root);
                root = root->left;
            }

            root = stackToken.top();
            stackToken.pop();
            res.push_back(root->val);
            root = root->right;

        }
        return res;


    }

    // https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/acm-xuan-shou-tu-jie-leetcode-er-cha-shu-q9ep/
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;

        if (root == nullptr) {
            return res;
        }
        // 首先初始化一个空栈。
        stack<TreeNode *> stackToken;
        while (!stackToken.empty() || root != nullptr) {

            // 从根节点开始，如果当前节点一直有左子树，那就一直向左子树遍历，同时将当前的节点压入栈中。
            while (root != nullptr) {
                stackToken.push(root);
                if (root->left != nullptr) {
                    root = root->left;
                } else {
                    root = root->right;
                }
            }

            root = stackToken.top();
            stackToken.pop();
            res.push_back(root->val);


            if (!stackToken.empty() && root == stackToken.top()->left) {
                root = stackToken.top()->right;
            } else {
                // 结束循环
                root = nullptr;
            }


        }
        return res;
    }


    // 层序遍历
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode *> queueTreeNodes;
        queueTreeNodes.push(root);
        while (!queueTreeNodes.empty()) {

            int sz = queueTreeNodes.size();
            vector<int> cens;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = queueTreeNodes.front();
                queueTreeNodes.pop();
                cens.push_back(node->val);
                if (node->left != nullptr) {
                    queueTreeNodes.push(node->left);
                }
                if (node->right != nullptr) {
                    queueTreeNodes.push(node->right);
                }

            }
            res.push_back(cens);


        }
        return res;


    }


};