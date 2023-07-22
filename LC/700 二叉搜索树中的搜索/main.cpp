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
public:
    TreeNode *searchBST(TreeNode *root, int target) {
        if (root == nullptr) {
            return nullptr;
        }if(root->val==target){
            return root;
        }else if (root->val < target) {
            return searchBST(root->right, target);
        } else if (root->val > target) {
            return searchBST(root->left, target);
        }
        return nullptr;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
