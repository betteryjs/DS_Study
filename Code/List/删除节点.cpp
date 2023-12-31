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

    ListNode *  deleteListNode (ListNode* head){
        // 带头节点 头节点不带值
        ListNode* cur= head->next;
        ListNode* pre=head; // pre指向头结点
        ListNode* min=cur; // 假设第一个结点为最小值的结点
        while (cur->next!= nullptr){
            if(cur->next->val < min->val){
                pre=cur;
                min=cur->next;
            }
            cur=cur->next;
        }
        pre->next=min->next; // 从链表上删除最小值结点
        free (min);
        return head;
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
    ListNode * node=new ListNode(-1);
    ListNode * nodes=solution->deleteListNode(head->next);
//
//
    buildlist.PrintLinkList(head);
    cout << nodes->val<<endl;
    delete solution;


}


