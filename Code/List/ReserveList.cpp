#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 非递归操作
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *nextCur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextCur;
        }
        return prev;
    }
};

// 递归操作 反转全部链表
class Solution2 {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;

        }

        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};


// 反转链表前 N 个节点

class Solution3 {
private:
    ListNode* nextCur= nullptr; // 后驱节点
public:
    ListNode *reverseList(ListNode *head,int n) {

       reverseN(head,n);

    }

    ListNode * reverseN(ListNode* head, int n){
        if(n==1){
            nextCur=head->next;
            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode * last= reverseN(head->next,n-1);
        head->next->next=head;
        head->next=nextCur;
        return last;
    }
};



// 反转链表的一部分
class Solution4 {
private:
    ListNode* nextCur= nullptr; // 后驱节点
public:
// [m,n] 索引从1开始
    ListNode *reverseBetween(ListNode *head,int m,int n) {
        if(m==1){

            return reverseN(head,n);
        }
        head->next= reverseBetween(head->next,m-1,n-1);
        return head;
    }

    ListNode * reverseN(ListNode* head, int n){
        if(n==1){
            nextCur=head->next;
            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode * last= reverseN(head->next,n-1);
        head->next->next=head;
        head->next=nextCur;
        return last;
    }
};








int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
