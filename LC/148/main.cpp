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

private:

    ListNode * marge(ListNode * head1,ListNode * head2){
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        while (head1!= nullptr && head2!= nullptr){
            if(head1->val<=head2->val){
                cur->next=head1;
                head1=head1->next;

            }else{
                cur->next=head2;
                head2=head2->next;
            }


            cur=cur->next;

        }
        cur->next= head1!= nullptr ? head1:head2;
        return dummyHead->next;





    }
public:



    ListNode* sortList(ListNode* head) {
        if (head== nullptr || head->next== nullptr) return head;


        // 要让fast 多走一步或两步
        // fast和slow同一起点的话，对于节点数为偶数的链表，返回的是中间两个节点的第二个，无法正确拆分偶数链表。例如，
        // 一个链表只有1,2两个节点，如果用上述代码，返回的中间节点是节点2，无法拆分。为了返回正确，需要让fast先走一步或两步
        ListNode * fast=head->next,*slow=head;
        while (fast!= nullptr && fast->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;

        }
        // slow is middle
        // 切链
        fast = slow->next, slow->next = nullptr;
        // fast 为后半部分


        return marge(sortList(head), sortList(fast));









    }


};


int main() {
    vector<int> nums{1, 325, 36, 17, 25, 56};

    BuildList buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Solution *solution = new Solution;
    ListNode *NewHead = solution->sortList(head);

    buildlist.PrintLinkList(head);
    return 0;
}
