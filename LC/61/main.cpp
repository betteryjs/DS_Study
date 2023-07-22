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


class Solution {



public:
    ListNode *rotateRight(ListNode *head, int k) {

        if(k==0 || head== nullptr || head->next== nullptr){
            return head;
        }

       int n=1;
        ListNode * tail=head;
        while (tail->next!= nullptr){
            tail=tail->next;
            n++;
        }
//        for(ListNode* p = head; p ; p = p->next){
//            tail = p;
//            n++;
//        }


        k %= n;
        ListNode* p = head;
        // [0 n-k-2] n-k-1 个元素
        for(int i = 0; i < n - k - 1; i++)   p = p->next;  //找到链表的第n-k个节点
        tail->next=head;
        head=p->next;
        p->next= nullptr;
        return head;















    }



};


int main() {
//    vector<int> nums{1, 2, 3, 4, 5};
//
//    BuildList buildlist(nums);
//    ListNode *head = buildlist.getHead();
//    buildlist.PrintLinkList(head);
//    Solution2 *solution = new Solution2;
//    ListNode *NewHead = solution->rotateRight(head,2);
//
//    buildlist.PrintLinkList(NewHead);

    return 0;
}
