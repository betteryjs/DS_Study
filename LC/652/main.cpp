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

    unordered_map<string,int> TreeNodeMapString;
    vector<TreeNode *> res;

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        traverse(root);
        return res;


    }

    string traverse(TreeNode * root){
        if(root== nullptr){
            return "#";
        }

        string left= traverse(root->left);
        string  right= traverse(root->right);
        string subTree=left+","+right+","+ to_string(root->val);
        if(TreeNodeMapString[subTree]==1){
            res.push_back(root);
        }
        TreeNodeMapString[subTree]++;
        return subTree;






    }

};



int main() {
    return 0;
}
