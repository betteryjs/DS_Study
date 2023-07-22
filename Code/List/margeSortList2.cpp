// 方法一：自顶向下归并排序

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
    ListNode *sortList(ListNode *head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }
// 要让fast 多走一步或两步
        // fast和slow同一起点的话，对于节点数为偶数的链表，返回的是中间两个节点的第二个，无法正确拆分偶数链表。例如，
        // 一个链表只有1,2两个节点，如果用上述代码，返回的中间节点是节点2，无法拆分。为了返回正确，需要让fast先走一步或两步
       ListNode *fast = head->next, *slow = head;
        // ListNode *fast = head, *slow = head;

        // fast slow node find the list middle node

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode *tmp = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);

        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;


            } else {

                cur->next = right;
                right = right->next;

            }

            cur = cur->next;


        }

        cur->next = left != nullptr ? left : right;
        return dummyHead->next;


    }


};





//  方法二：自底向上归并排序






int main() {
    vector<int> nums{1, 325, 36, 17, 25, 56};

    BuildListHavePoint buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Solution *solution = new Solution;
    ListNode *NewHead = solution->sortList(head);

    buildlist.PrintLinkList(head);

    return 0;


}