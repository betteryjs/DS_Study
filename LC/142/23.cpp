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


class Test {

private:

    unordered_set<int> setCount;

public:


    ListNode *cleanList(ListNode *head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head->next;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr) {
            if (setCount.count(abs(cur->next->val))) {

                cur->next = cur->next->next;
            } else {
                setCount.insert(abs(cur->next->val));

                cur = cur->next;
            }


        }
        return dummyHead;


    }


};


class Test2 {

private:

    unordered_set<int> setCount;
    vector<int> set;

public:


    ListNode *cleanList(ListNode *head,int n) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        set.reserve(n+1);

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head->next;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr) {
            if ( set[abs(cur->next->val)]==1) {

                cur->next = cur->next->next;
            } else {

                set[abs(cur->next->val)]=1;

                cur = cur->next;
            }


        }
        return dummyHead;


    }





};



int main() {
    vector<int> nums{1, 1, -2, -1, 36, 2, 17, 25, -25, 56};

    BuildListHavePoint buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Test *test = new Test();
    ListNode *ans = test->cleanList(head);
//    cout << ans->val;
    buildlist.PrintLinkList(ans);


    return 0;


}
