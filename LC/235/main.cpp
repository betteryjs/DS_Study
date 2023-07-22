#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {


        TreeNode *ans = root;
        while (true) {

            if (ans->val > p->val && ans->val > q->val) {
                ans = ans->left;
            } else if (ans->val < q->val && ans->val < p->val) {
                ans = ans->right;
            } else {
                break;
            }

        }


        return ans;


    }
};


class Solution2 {

private:
    vector<TreeNode * > getPath(TreeNode * root,TreeNode * target){
        vector<TreeNode * >path;
        TreeNode * node=root;
        while (node!=target){
            path.push_back(node);
            if(target->val<node->val){
                node=node->left;
            }else{
                node=node->right;
            }

        }
        path.push_back(target);
        return path;
    }

public:

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode * >path1= getPath(root,p);
        vector<TreeNode * >path2= getPath(root,q);
        TreeNode * ans;
        for (int i = 0; i < path1.size() && i<path2.size(); ++i) {

            if(path1[i]==path2[i]){
                ans=path2[i];
            }

        }
        return ans;
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
