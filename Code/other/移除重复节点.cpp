//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
        int val;
        ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* pre= nullptr;
        ListNode* cur= head;
        unordered_set<int> visited;
        while (cur!= nullptr){
            if(visited.find(cur->val)!=visited.end()){
                pre->next=cur->next;
            }else{
                visited.emplace(cur->val);
                pre=cur;
            }
            cur=cur->next;
        }
        return head;








    }
};
int main() {

    return 0;
}