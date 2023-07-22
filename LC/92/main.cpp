#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 递归
class Solution {

private:
    ListNode *nextCur = nullptr; // 后驱节点
public:

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;


    }

    ListNode *reverseN(ListNode *head, int n) {
        if (n == 1) {
            nextCur = head->next;
            return head;

        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = nextCur;
        return last;
    }
};


// 穿针引线
class Solution2 {

private:
     //  迭代
    ListNode* reverseLinkedList1(ListNode *head) {

        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    //  递归
    ListNode* reverseLinkedList2(ListNode *head) {

        if (head == nullptr || head->next == nullptr) {
            return head;

        }
        ListNode *last = reverseLinkedList1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

public:

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;


        // 虚拟节点走 left-1 步
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;

        }
        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点


        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; ++i) {
            rightNode = rightNode->next;
        }

        // 第 3 步：切断出一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *curNode = rightNode->next;

        // 注意：切断链接
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 第 4 步：反转链表的子区间
        reverseLinkedList1(leftNode);



        //  连接链表

        pre->next = rightNode;
        leftNode->next = curNode;
        return dummy->next;


    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
