#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
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


class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *dummyHead1 = new ListNode(-1);
        ListNode *cur1 = dummyHead1;
        ListNode *dummyHead2 = new ListNode(-1);
        ListNode *cur2 = dummyHead2;
        ListNode *cur = head;
        int len = 0;
        while (cur != nullptr) {

            len++;

            if (len & 1) {
                cur1->next = cur;
                cur1 = cur1->next;
            } else {
                cur2->next = cur;
                cur2 = cur2->next;

            }


            cur = cur->next;
        }
        cur2->next = nullptr;
        cur1->next = dummyHead2->next;
        return dummyHead1->next;


    }
};



// 穿针引线

class Solution2 {
public:

    ListNode *oddEvenList(ListNode *head) {
        if(head== nullptr){
            return nullptr;
        }

        ListNode  * old=head;
        ListNode * eventNew=head->next;
        ListNode  * event=eventNew;

        while (event!= nullptr  && event->next!= nullptr){
            old->next=event->next;
            old=old->next;
            event->next=old->next;
            event=event->next;




        }
        old->next=eventNew;
        return head;



    }


};


int main() {
    vector<int> nums{1, 325, 36, 17, 25, 56};

    BuildListHavePoint buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);


    return 0;
}
