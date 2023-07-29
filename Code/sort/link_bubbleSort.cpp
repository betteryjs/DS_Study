//
// Created by yjs on 23-7-29.
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
    void ListNodeSwap(ListNode *prevNode, ListNode *node1, ListNode *node2) {
        node1->next = node2->next;
        prevNode->next = node2;
        node2->next = node1;
    }
    static string ppint(ListNode *head) {
        ListNode *cur = head;
        string res = "";
        int count = 0;
        while (cur != nullptr) {
            count++;
            res = res + to_string(cur->val) + " ";
            cur = cur->next;
        }
        return " [" + to_string(count) + "] " + res + "\n";


    }


public:

    ListNode *BubbleSort(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyCurser = dummyHead;

        while (head->next != nullptr) {
            ListNode *cur = head->next;
            ListNode *pre = head; // pre指向头结点
            while (cur->next != nullptr) {
                if (cur->val < cur->next->val) {
                    ListNodeSwap(pre, cur, cur->next);
                } else {
                    cur = cur->next;

                }
                pre = pre->next;
            }
            cout << "cur is " << cur->val << endl;
            dummyCurser->next = cur;
            dummyCurser = dummyCurser->next;
            pre->next = nullptr;

        }

        return dummyHead->next;


    }


};





int main() {

    vector<int> nums{12, 25, 36, 17, 78, 65, 25, 56, 1};
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;

    for (int i = 0; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    cout << Solution::ppint(head->next) << endl;
    Solution solution;
//    for (int i = 0; i < 7; ++i) {
//        head=solution.deleteListNode(head);
//        cout << ppint(head->next)<<endl;
//    }
    ListNode *res = solution.BubbleSort(head);
    cout << Solution::ppint(res) << endl;


}