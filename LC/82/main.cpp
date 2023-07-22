#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// unordered_map
class Solution {
private:

    unordered_map<int, int> hashMap;
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *cur = head;
        while (cur != nullptr) {

            hashMap[cur->val]++;
            cur = cur->next;
        }


        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur3 = dummyHead;
        ListNode *cur1 = head;

        while (cur1 != nullptr) {
            if (hashMap[cur1->val] == 1) {
                cur3->next = cur1;
                cur3 = cur3->next;
            }
            cur1 = cur1->next;

        }
        cur3->next = nullptr;
        return dummyHead->next;
    }
};



// unordered_map
class Solution2 {
private:

    unordered_map<int, int> hashMap;
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *cur = head;
        while (cur != nullptr) {

            hashMap[cur->val]++;
            cur = cur->next;
        }


        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *cur1 = dummyHead;


        while (cur1->next != nullptr) {
            if (hashMap[cur1->next->val] != 1) {
                cur1->next = cur1->next->next;
            } else {
                cur1 = cur1->next;
            }
        }
        cur1->next = nullptr;
        return dummyHead->next;
    }
};



class Solution3 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        while(head){
            if(head->next == nullptr or head->val != head->next->val){
                tail->next = head;
                tail = tail->next ;
            }
            while(head->next and head->val == head->next->val) head = head->next;
            head = head->next;
        }


        // 切断后面的链表
        tail->next = nullptr;

        return dummy->next;
    }
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
        if (nums.size() >= 1) {
            this->head = new ListNode(nums[0]);
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
    vector<int> nums{1, 2, 2};

    BuildListNoPoint buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Solution2 *solution = new Solution2;
    ListNode *NewHead = solution->deleteDuplicates(head);

    buildlist.PrintLinkList(head);
    return 0;
}
