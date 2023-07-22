//
// Created by yjs on 2022/5/14.
//

#include <iostream>

using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @solution-sync:begin
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        // 判断是否存在环路
        while (true){
            if(fast== nullptr || fast->next== nullptr){
                return nullptr;
            }
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                break;
            }
        }

        // fast 记录fast=slow时的node节点
        // 如果存在，查找环路节点
        fast=head;

        while (fast!=slow  ) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};







