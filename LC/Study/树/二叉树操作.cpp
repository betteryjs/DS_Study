//
// Created by yjs on 2022/4/24.
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

    void visit(TreeNode *node) {
        cout << node->val << " ";
    }

    vector<int> res;

public:

    // 递归遍历二叉树
    void preOrder(TreeNode *root) {

        if (root != nullptr) {
            visit(root);
            preOrder(root->left);
            preOrder(root->right);

        }
    }

    void inOrder(TreeNode *root) {

        if (root != nullptr) {
            preOrder(root->left);
            visit(root);
            preOrder(root->right);

        }
    }

    void postOrder(TreeNode *root) {

        if (root != nullptr) {
            preOrder(root->left);
            preOrder(root->right);
            visit(root);
        }
    }

    // 非递归先序遍历二叉树 [根 左 右]
    // https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-de-qian-xu-bian-li-by-leetcode-solution/
    void preOrderTter(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        stack<TreeNode *> stackToken;
        while (root != nullptr || !stackToken.empty()) {
            // 从节点开始依次访问
            while (root != nullptr) {
                stackToken.push(root);
                visit(root);
                root = root->left;
            }
            TreeNode *cur = stackToken.top();
            root = cur->right;
        }
    }

//    void preOrderTter2(TreeNode *root) {
//        if(root== nullptr){
//            return;
//        }
//        stack<TreeNode * >stackToken;
//        while (!stackToken.empty()){
//            TreeNode* node=stackToken.top();
//            stackToken.pop();
//            visit(node);
//
//
//            if (node->right != nullptr) {
//                stackToken.push(node->right);
//            }
//            if (node->left != nullptr) {
//                stackToken.push(node->left);
//            }
//
//
//
//        }
//
//
//    }


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


    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stackToken;
        TreeNode *prev = nullptr;

        while (!stackToken.empty() || root != nullptr) {

            while (root != nullptr) {

                stackToken.push(root);
                root = root->left;
            }

            root = stackToken.top();
            stackToken.pop();
            if (root->right == nullptr || root->right == prev) {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stackToken.push(root);
                root = root->right;

            }


        }
        return res;
    }


    // 层次遍历
    void levelTraverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode *> queueTreeNodes;
        queueTreeNodes.push(root);
        while (!queueTreeNodes.empty()) {
            int sz = queueTreeNodes.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = queueTreeNodes.front();
                visit(node);
                queueTreeNodes.pop();
                if (node->left != nullptr) {
                    queueTreeNodes.push(node->left);
                }
                if (node->right != nullptr) {
                    queueTreeNodes.push(node->right);
                }
            }
        }
    }

    // 求树的最大高度
    int maxDeep(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDeep(root->left);
        int rightMax = maxDeep(root->right);
        return 1 + max(leftMax, rightMax);
    }


};