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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums,0,nums.size()-1);








    }


    TreeNode * build(vector<int> & nums,int left,int mid){
        // base case
        if(left>mid){
            return nullptr;
        }

        int maxIndex=max_element(nums.begin()+left,nums.begin()+mid+1)-nums.begin();
        cout << maxIndex <<endl;

        TreeNode * root= new TreeNode(nums[maxIndex]);
        root->left= build(nums,left,maxIndex-1);
        root->right= build(nums,maxIndex+1,mid);

        return root;







    }


};

int main() {
    Solution go;

    vector<int> nums{3,2,1,6,0,5};
    go.constructMaximumBinaryTree(nums);
    return 0;
}
