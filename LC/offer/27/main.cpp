#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @solution-sync:begin
// 递归法
class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};

class Solution2 {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        stack<TreeNode *> stackTreeNode;
        stackTreeNode.push(root);
        while (!stackTreeNode.empty()) {
            TreeNode *node = stackTreeNode.top();
            stackTreeNode.pop();
            if (node->left != nullptr) {
                stackTreeNode.push(node->left);
            }
            if (node->right != nullptr) {
                stackTreeNode.push(node->right);
            }
            swap(node->left, node->right);
        }
        return root;


    }
};



// @solution-sync:end

struct NullableInt {
    int val;
    bool null;

    NullableInt(int val, bool null) : val(val), null(null) {}
};

TreeNode *parseTreeNode(vector<NullableInt> values) {
    TreeNode *root;
    queue<TreeNode *> nodes;
    int i = 0;
    while (i < values.size()) {
        if (i == 0) {
            root = new TreeNode(values[i].val);
            i += 1;
            nodes.push(root);
            continue;
        }

        TreeNode *parent = nodes.front();
        nodes.pop();
        if (!values[i].null) {
            auto left = new TreeNode(values[i].val);
            parent->left = left;
            nodes.push(left);
        }

        if (i + 1 < values.size() && !values[i + 1].null) {
            auto right = new TreeNode(values[i + 1].val);
            parent->right = right;
            nodes.push(right);
        }

        i = i + 2;
    }
    return root;
}

#include <sstream>

int getLevelCount(TreeNode *node) {
    if (node == nullptr) return 0;
    int leftMaxLevel = 1 + getLevelCount(node->left);
    int rightMaxLevel = 1 + getLevelCount(node->right);
    return leftMaxLevel > rightMaxLevel ? leftMaxLevel : rightMaxLevel;
}

void toString(stringstream &out, TreeNode *node, int level) {
    if (level == 0) {
        if (node != nullptr)
            out << node->val;
        else
            out << "null";
        out << ",";
    }
    if (node != nullptr) {
        toString(out, node->left, level - 1);
        toString(out, node->right, level - 1);
    }
}

bool endsWith(const std::string &mainStr, const std::string &toMatch) {
    return mainStr.size() >= toMatch.size() &&
           mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0;
}

string toString(TreeNode *root) {
    stringstream out;
    int levelCount = getLevelCount(root);
    for (int i = 0; i < levelCount; ++i)
        toString(out, root, i);
    auto r = out.str();
    r = r.substr(0, r.size() - 1);
    return "[" + r + "]";
}

int main() {
    TreeNode *root = parseTreeNode(vector<NullableInt>{
            NullableInt(4, false),
            NullableInt(2, false),
            NullableInt(7, false),
            NullableInt(1, false),
            NullableInt(3, false),
            NullableInt(6, false),
            NullableInt(9, false)
    });

    auto solution = Solution();
    auto result = solution.mirrorTree(root);
    cout << toString(result) << endl;

    return 0;
}
