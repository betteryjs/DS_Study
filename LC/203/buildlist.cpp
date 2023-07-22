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


class BuildList {
public:


    ListNode *buildLinkList(ListNode *headA, ListNode *headB) {
        if (headA == nullptr) {
            return headB;
        }
        if (headB == nullptr) {
            return headA;
        }

        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur1 = dummyHead;
        ListNode *cur2 = headA->next;
        ListNode *cur3 = headB->next;
        while (cur2 != nullptr && cur3 != nullptr) {
            if (cur2->val < cur3->val) {
                cur1->next = cur2;
                cur2 = cur2->next;
            } else if (cur2->val == cur3->val) {
                cur1->next = cur2;
                cur2 = cur2->next;
                cur3 = cur3->next;
            } else {
                cur1->next = cur3;
                cur3 = cur3->next;
            }
            cur1 = cur1->next;

        }

        cur1->next=cur2!= nullptr ? cur2:cur3;
        return dummyHead;
    }

};



class BuildListHavePoint {

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

    BuildListHavePoint(const vector<int> &nums) : nums(nums) {
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


int main(){


    vector<int> nums1{1, 12, 17, 22,25, 56};
    vector<int> nums2{1, 15, 17,23,25,56};

    BuildListHavePoint buildlist1(nums1);
    ListNode *head1 = buildlist1.getHead();
    buildlist1.PrintLinkList(head1);

    BuildListHavePoint buildlist2(nums2);
    ListNode *head2= buildlist2.getHead();
    buildlist2.PrintLinkList(head2);





    BuildList *solution = new BuildList;
    ListNode *NewHead = solution->buildLinkList(head1,head2);

    buildlist2.PrintLinkList(NewHead);
    return 0;
}