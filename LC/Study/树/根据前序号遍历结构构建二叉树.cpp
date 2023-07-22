//
// Created by yjs on 2022/4/29.
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
    TreeNode* bstFromPreorder(vector<string>& preorder) {
        queue<string>queueNodes;
        for (int i = 0; i < preorder.size(); ++i) {
            queueNodes.push(preorder[i]);

        }

    }
    TreeNode * build(queue<string> & queue){
        string val=queue.front();
        queue.pop();
        if(val=="null"){
            return nullptr;
        }
        TreeNode * root=new TreeNode(atoi(val.c_str()));
        root->left= build(queue);
        root->right= build(queue);
        return root;



    }
};





int main(){


    vector<string> preorder {"2","3","7","8","4","null","null"};




    return 0;
}



