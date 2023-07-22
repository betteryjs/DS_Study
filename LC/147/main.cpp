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
    ListNode *insertionSortList(ListNode *head) {

        if (head == nullptr) {
            return head;
        }
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *lastSorted = head;
        ListNode *cur = head->next;
        while (cur != nullptr) {

            if (lastSorted->val <= cur->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= cur->val) {
                    prev = prev->next;
                }
                lastSorted->next = cur->next;
                // 将cur插入到 prev 后
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }
        return dummyHead->next;
    }
};e


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
    vector<int> nums{1, 325, 36, 17, 25, 56};

    BuildList buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Solution *solution = new Solution;
    ListNode *NewHead = solution->insertionSortList(head);

    buildlist.PrintLinkList(head);
    return 0;
}
