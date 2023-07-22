//
// Created by yjs on 2022/4/28.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:

    // postorder [左 右 根]
    // preorder [根 左 右]
    vector<int> preorder;
    vector<int> postorder;
    unordered_map<int, int> index;

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {

        this->preorder = preorder;
        this->postorder = postorder;
        int n = postorder.size();
        for (int i = 0; i < n; ++i) {
            index[postorder[i]] = i;
        }
        return buildTreeHelper(0, n - 1, 0, n - 1);


    }

    TreeNode *buildTreeHelper(const int &preStart, const int &preEnd, const int &postStart, const int &postEnd) {

        if ( preStart> preEnd ) {
            return nullptr;
        }
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // postorder [左 右 根]

        // preorder [根 左 右]
        // 1、首先把前序遍历结果的第一个元素确定为根节点的值。
        //2、然后把前序遍历结果的第二个元素作为左子树的根节点的值。
        //3、在后序遍历结果中寻找左子树根节点的值，从而确定了左子树的索引边界，进而确定右子树的索引边界，递归构造左右子树即可。
        int rootVal=this->preorder[preStart];
        int leftRootVal = this->preorder[preStart + 1];
        int indexLeftRoot= index[leftRootVal];
        // 左子树的元素个数
        int leftSize = indexLeftRoot - postStart + 1;
        // 先构造出当前根节点
        TreeNode * root = new TreeNode(rootVal);
        root->left= buildTreeHelper(preStart+1,preStart+leftSize,postStart,indexLeftRoot);
        root->right= buildTreeHelper(preStart+leftSize+1,preEnd,indexLeftRoot+1,postEnd-1);
        return root;

    }
};