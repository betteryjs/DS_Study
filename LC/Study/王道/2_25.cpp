//
// Created by yjs on 2022/5/15.
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

    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *nextCur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextCur;
        }
        return prev;
    }


public:

    ListNode *doList(ListNode *head) {
        // fastfind mid
        ListNode * fast=head,*slow=head;
        while (fast!= nullptr && fast->next!= nullptr){

            fast=fast->next->next;
            slow=slow->next;

        }

        // slow is middle


        ListNode * middle=slow->next;
        // cur link list
        slow->next= nullptr;

        ListNode * last=reverse(middle);
        ListNode * cur1=head->next;
        ListNode * cur2=last;
        while (cur2!= nullptr){
            ListNode * nextCur2=cur2->next;
            // cur2 插入到cur1后面
            cur2->next=cur1->next;
            cur1->next=cur2;
            cur1=cur2->next;
            cur2=nextCur2;


        }
        return head;

    }

};

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    BuildListHavePoint buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Test *test = new Test();
    ListNode *ans = test->doList(head);
//    cout << ans->val;
    buildlist.PrintLinkList(ans);


}