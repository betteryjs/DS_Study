/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode *getMid(ListNode * left,ListNode * right){
        auto slow=left;
        auto fast=left;
        while(fast !=right && fast->next !=right){

            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;


    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head,nullptr);

    }
    TreeNode* buildTree(ListNode* left,ListNode * right) {
        if(left==right){
            return nullptr;
        }
        ListNode * mid=getMid(left,right);
        TreeNode * root=new TreeNode(mid->val);
        root->left=buildTree(left,mid);
        root->right=buildTree(mid->next,right);
        return root;
    }
};
