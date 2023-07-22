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
class Solution {
public:
    bool isSymmetric(TreeNode *root) {

        if (root == nullptr) {
            return true;
        } else {
            return recur(root->left, root->right);

        }


    }

    bool recur(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr || left->val != right->val) {
            return false;
        }
        return recur(left->left, right->right) && recur(left->right, right->left);

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
    auto result = solution.isSymmetric(root);
    cout << result << endl;

    return 0;
}
