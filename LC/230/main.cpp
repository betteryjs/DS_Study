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
    // 小根堆
    priority_queue<int, vector<int>, greater<int>> priorityQueue;

public:
    int kthSmallest(TreeNode *root, int k) {
        traverse(root);
        while (--k && !priorityQueue.empty()) {
            priorityQueue.pop();
        }
        return priorityQueue.top();

    }

    void traverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        priorityQueue.push(root->val);
        traverse(root->left);
        traverse(root->right);

    }

};


class Solution2 {
private:
    int k;
    int res;
    int rack = 0;

public:
    int kthSmallest(TreeNode *root, int k) {
        this->k = k;
        traverse(root);
        return res;


    }

    void traverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left);
        rack++;
        if (k == rack) {
            res = root->val;
            return;
        }


        traverse(root->right);

    }

};


int main() {
    Solution go;

    return 0;
}
