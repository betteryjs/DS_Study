//
// Created by yjs on 2022/5/13.
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


class CutLinkList {

public:

    ListNode *cutList(ListNode *headA) {
        ListNode *dummyHeadA = new ListNode(-1);
        ListNode *dummyHeadB = new ListNode(-1);
        ListNode *cur1 = dummyHeadA;
        ListNode *cur2 = dummyHeadB;
        ListNode *p = headA->next;
        int len = 0;
        while (p != nullptr) {
            len++;
            if (len % 2 == 1) {
                cur1->next = p;
                cur1 = p;
            } else {
                cur2->next = p;
                cur2 = p;
            }
            p = p->next;
        }
        cur1->next = nullptr;
        cur2->next = nullptr;
        headA = dummyHeadA;
        return dummyHeadB;
    }


};


class BuildList {

private:


    vector<int> nums;

private:


    bool InsertNextNode(ListNode *p, const int &e) {

        if (p == nullptr) {
            return false;
        }
        ListNode *s = new ListNode(e);
        s->next = p->next;
        p->next = s;
        return true;
    }

    ListNode *head = new ListNode(-1);


public:

    BuildList(const vector<int> &nums) : nums(nums) {
        ListNode *cur = this->head;

        ListTailInsert(cur, nums);


    }

    ListNode *ListTailInsert(ListNode *head, const vector<int> &nums) {
        ListNode *pos1 = head;
        for (const int &num: nums) {
            InsertNextNode(pos1, num);
            pos1 = pos1->next;
        }
        return head;
    }


    void PrintLinkList(ListNode *head) {
        ListNode *cur = head->next;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;


        }
        cout << endl;

    }


    ListNode *getHead() {

        return this->head;

    }


};


int main() {

    vector<int> nums{1, 12, 36, 17, 25, 56};

    BuildList buildlist(nums);
    ListNode *head = buildlist.getHead();
//    cout << head->val<<endl;
    buildlist.PrintLinkList(head);
    CutLinkList *solution = new CutLinkList;
    ListNode *NewHead = solution->cutList(head);

    buildlist.PrintLinkList(head);
    buildlist.PrintLinkList(NewHead);
//cout << NewHead->val<<endl;

}