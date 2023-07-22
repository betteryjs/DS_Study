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


// priority_queue
class Solution {
private:
    struct cmp {
        bool operator()(const ListNode *l1, const ListNode *l2) {

            return l1->val > l2->val;

        }

    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        // 优先级队列，最小堆
        priority_queue<ListNode *, vector<ListNode *>, cmp> priorityQueue;


        for (ListNode *list: lists) {
            if (list != nullptr) {

                priorityQueue.push(list);

            }

        }

        while (!priorityQueue.empty()){


            // 获取最小节点，接到结果链表中
            ListNode * node=priorityQueue.top();
            priorityQueue.pop();
            cur->next=node;

            if(node->next!= nullptr){
                priorityQueue.push(node->next);
            }
            cur=cur->next;



        }
        return dummy->next;


    }
};


class Solution2{

private:

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

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }




};


class Solution3{

private:

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

public:


    ListNode *  merge(vector<ListNode * >lists,int l ,int r){
        if(l==r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));





    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

    }




};



