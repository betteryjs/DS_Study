//
// Created by yjs on 2022/5/14.
//



#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {

public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *x = findFromEnd(dummyHead, n+1);
        x->next = x->next->next;
        return dummyHead->next;


    }


    // 返回链表的倒数第 k 个节点


    ListNode *findFromEnd(ListNode *head, int k) {

        ListNode *fast = head;
        // fast 先走 k 步
        while (k--) {

            fast = fast->next;
        }

        ListNode *slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;


    }


};