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
    int len = 0;
    ListNode *head;

public:
    Solution(ListNode *head) {
        ListNode *cur = head;
        this->head = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        // 1 -> 22 -> 31 -> 45   len =4

    }

    int getRandom() {
        int random = rand() % len; // 0 1 2 3
        ListNode *cur = this->head;
        while (random--) {
            cur = cur->next;
        }
        return cur->val;
    }
};


class Solution2 {
private:
    vector<int> arr;

public:
    Solution2(ListNode *head) {
        ListNode *cur = head;
        while (cur) {
            arr.emplace_back(cur->val);
            cur = cur->next;
        }


    }

    int getRandom() {


        return arr[rand() % arr.size()];

    }


};


// 蓄水池抽样

class Solution3 {

private:
    ListNode *head;

public:

    Solution3(ListNode *head) {
        this->head = head;
    }

    int getRandom() {
        int ans = 0;
        int idx = 0;
        ListNode *cur = head;
        while (cur) {
            idx++;
            if (rand() % idx == 0) {

                ans = cur->val;
            }


            cur = cur->next;

        }
        return ans;

    }

};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main() {
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;

    Solution *obj = new Solution(head);
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
//    cout << obj->getRandom()<<endl;
//    cout << obj->getRandom()<<endl;
    return 0;
}
