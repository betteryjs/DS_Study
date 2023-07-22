#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head,*slow=head;
        while (fast!= nullptr && fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                // 有环
                break;
            }
        }
        if(fast== nullptr || fast->next== nullptr){
            // 链表没有环
            return nullptr;
        }
        // slow 重新指向head
        slow=head;
        while (slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
