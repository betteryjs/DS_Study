
#include<iostream>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    void traverse(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        res.push_back(root->val);
        traverse(root->left, res);
        traverse(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);

        return res;
    }
};

// reference: leetcode playground
TreeNode* deserilize(string data) {
    if (data.empty()) {
        return nullptr;
    }

    istringstream ss(data);
    string token;
    getline(ss, token, ',');

    TreeNode *root = new TreeNode(stoi(token)), *cur = root;
    queue<TreeNode*> que;
    que.push(cur);

    while(!que.empty()) {
        TreeNode* node = que.front();
        que.pop();

        if (!getline(ss, token, ',')) {
            break;
        }

        if (token != "null") {
            TreeNode* left = new TreeNode(stoi(token));
            node->left = left;
            que.push(left);
        }

        if (!getline(ss, token, ',')) {
            break;
        }
        if (token != "null") {
            TreeNode* right = new TreeNode(stoi(token));
            node->right = right;
            que.push(right);
        }
    }
    return root;
}

int main()
{
    string tree = "1,null,4,7,8";
    TreeNode* root = deserilize(tree);
    /*        1
     *       / \
     *     null 4
     *         / \
     *        7   8
     */

    Solution solution;
    vector<int> res = solution.preorderTraversal(root);

    for (auto i : res) {
        std::cout << i << " ";
    }

    return 0;
}
