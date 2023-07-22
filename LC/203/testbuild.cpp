//
// Created by yjs on 2022/5/13.
//

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




class BuildListNoPoint {

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

    ListNode *head = nullptr;


public:

    BuildListNoPoint(const vector<int> &nums) : nums(nums) {
        if(nums.size()>=1){
            this->head=new ListNode(nums[0]);
        }
        ListNode *cur = this->head;


        ListTailInsert(cur, nums);


    }

    ListNode *ListTailInsert(ListNode *head, const vector<int> &nums) {
        ListNode *pos1 = head;
        for (int i = 1; i < nums.size(); ++i) {
            InsertNextNode(pos1, nums[i]);
            pos1 = pos1->next;

        }



        return head;
    }


    void PrintLinkList(ListNode *head) {
        ListNode *cur = head;
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

    vector<int> nums{1,36,24};

    BuildListNoPoint buildlist(nums);
    ListNode *head = buildlist.getHead();

    buildlist.PrintLinkList(head);
    cout << head->val<<endl;

}