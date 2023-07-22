//
// Created by yjs on 2022/2/24.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next!= nullptr) {
            //慢指针每次"迈一步"
            slow = slow->next;
            //快指针每次"迈两步"
            fast = fast->next->next;


            if(fast == slow) {
                //指针p从链表首节点出发
                fast = head;
                while( fast != slow ){
                    //指针p和慢指针每次都迈一步
                    slow = slow->next;
                    fast = fast->next;
                }
                //指针p和慢指针会在“环开始的节点”相遇
                return fast;

            }
        }



        return nullptr;

    }
};

int main() {

    return 0;
}