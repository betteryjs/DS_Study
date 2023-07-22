//
// Created by yjs on 2022/5/16.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur3 = dummyHead;


        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                cur3->next = list1;
                list1 = list1->next;
            } else {
                cur3->next = list2;
                list2 = list2->next;
            }
            cur3 = cur3->next;


        }

        cur3->next = list1 != nullptr ? list1 : list2;
        return dummyHead->next;


    }
};