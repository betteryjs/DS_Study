#include <iostream>

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
    void flatten(TreeNode* root) {
        if(root== nullptr){
            return;
        }

        // 利用定义，把左右子树拉平
        flatten(root->left);
        flatten(root->right);

        // 1、左右子树已经被拉平成一条链表
        TreeNode * left=root->left;
        TreeNode * right=root->right;


        // 2、将左子树作为右子树
        root->left= nullptr;
        root->right=left;
        TreeNode * p=root;
        while (p->right!= nullptr){

            p=p->right;
        }
        p->right=right;




    }


};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
