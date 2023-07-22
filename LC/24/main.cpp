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

private:

    ListNode *reserve(ListNode *head, ListNode *end) {

        ListNode *cur = head;
        ListNode *prev = nullptr;
        while (cur != end) {
            ListNode *nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;


        }
        return prev;


    }


public:
    ListNode *swapPairs(ListNode *head) {
        // 两个一组反转

        if (head == nullptr) {
            return nullptr;
        }

        ListNode *a = head, *b = head;
        int k = 2;

        for (int i = 0; i < k; ++i) {
            if (b == nullptr) {
                return head;
            }
            b = b->next;

        }

        // 反转前K 个元素
        ListNode *newHead = reserve(a, b);
        a->next = swapPairs(b);
        return newHead;


    }
};

int main() {


    return 0;

}
