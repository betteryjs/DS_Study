


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * x = findFromEnd(dummy, n + 1);
        x->next=x->next->next;
        return dummy->next;

    }
    // 返回链表的倒数第 k 个节点
    ListNode* findFromEnd(ListNode* head, int k){
        ListNode * cur1=head;
        // p1 先走 k 步
        while (k--){
            cur1=cur1->next;
        }
        ListNode* cur2 = head;
        while (cur1!= nullptr){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        // cur2 现在指向第 n - k 个节点
        return cur2;
       }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
