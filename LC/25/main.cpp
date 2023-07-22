#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

private:
    // 反转区间 [a, b) 的元素
    ListNode *reverse(ListNode *head, ListNode *end) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != end) {
            ListNode *nextCur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextCur;
        }
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *a = head, *b = head;
        for (int i = 0; i < k; ++i) {
            // 如果剩余反转的长度小于K 直接返回head
            if (b == nullptr) {
                return head;
            }
            b = b->next;
        }
        // 反转前K 个元素
        ListNode *newHead = reverse(a, b);
        // 递归反转后续链表并连接起来
        a->next = reverseKGroup(b, k);
        return newHead;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
