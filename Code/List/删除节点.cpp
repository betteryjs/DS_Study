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


class Solution{

public:

    ListNode * deleteListNode(ListNode* head){
        ListNode * prevMin=head;
        ListNode * Min=head;
        ListNode * cur=head;
        while(cur->next!= nullptr){
            cout << " node is "<<cur->val<<endl;

            if(Min->val<=cur->next->val){
              cur=cur->next;
            }else{
                prevMin=cur;
                Min=prevMin->next;
                cur=cur->next;
            }
        }
        cout << "delete node is "<<Min->val<<endl;
        cout << "prev min is " << prevMin->val <<endl;
//        prevMin=prevMin->next;
        prevMin->next=Min->next;



        return  head;
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

    vector<int> nums{ 12,25, 36, 17, 25, 56,1};

    BuildList buildlist(nums);
    ListNode *head = buildlist.getHead();
//    cout << head->val<<endl;

    buildlist.PrintLinkList(head);
    Solution * solution=new Solution;
    ListNode * node=solution->deleteListNode(head->next);
//
//
    buildlist.PrintLinkList(head);
    delete solution;


}


