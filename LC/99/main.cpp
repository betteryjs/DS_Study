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
    // [1 2 3 *7 5 6 *4]
private:
    // 分别记录这两个被交换的节点
    TreeNode * first= nullptr,*second= nullptr;
    TreeNode *prev=new TreeNode(INT_MIN);

public:
    void recoverTree(TreeNode *root) {


        inorderTraverse(root);
        swap(first->val,second->val);




    }
    void  inorderTraverse(TreeNode*  node){

        if(node== nullptr){
            return;
        }

        inorderTraverse(node->left);

        if(prev->val>node->val){
            if(first== nullptr){
                first=prev;
            }
            second=node;

        }
        prev=node;


        inorderTraverse(node->right);


    }
};


class  Solution2{

private:

    vector<TreeNode* > list;
public:


    void recoverTree(TreeNode *root) {

        dfs(root);
        TreeNode * x= nullptr , *y= nullptr;
        for (int i = 0; i < list.size()-1; ++i) {

            if(list[i]->val> list[i+1]->val){
                y=list[i+1];
                if(x== nullptr){

                    x=list[i];
                }


            }
            
        }
        if(x!= nullptr && y!= nullptr){

            swap(x->val,y->val);


        }


    }


        void  dfs(TreeNode * node){

        if(node== nullptr){
            return;
        }
        dfs(node->left);
        list.push_back(node);
        dfs(node->right);



    }




};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
