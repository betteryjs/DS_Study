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
    // preorder [根 左 右]
    // inorder [左 根 右]
private:
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int,int> index;
    


public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder=preorder;
        this->inorder=inorder;
        // 构造哈希映射，帮助我们快速定位根节点
        int n=preorder.size();
        for (int i = 0; i < preorder.size(); ++i) {
            index[inorder[i]]=i;
        }
        return buildTreeHelper(0,n-1,0,n-1);
    }

    TreeNode * buildTreeHelper(const int & preStart,const int & preEnd,const int  & inStart,const int & inEnd){
        if(preStart>preEnd || inStart>inEnd){

            return nullptr;
        }


        // preorder
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=index[root->val]; // [左 根 右]
        int numsLeft=inRoot-inStart;
        root->left= buildTreeHelper(preStart+1,preStart+numsLeft,inStart,inRoot-1);
        root->right= buildTreeHelper(preStart+numsLeft+1,preEnd,inRoot+1,inEnd);
        return root;






    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
