//
// Created by yjs on 23-3-28.
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
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        vector<pair<TreeNode * , unsigned long long>> ans;
        ans.emplace_back(root,1L);
        while(!ans.empty()){

            vector<pair<TreeNode * , unsigned long long>> tmp;
            for(auto &[node, count] : ans){
                if(node->left!=nullptr){
                    tmp.emplace_back(node->left, 2*count);
                }
                if(node->right!=nullptr){

                    tmp.emplace_back(node->right, 2*count+1);
                }
            }
            res=max(res,ans.back().second-ans[0].second+1);
            ans=std::move(tmp);
        }
        return res;
    }
};