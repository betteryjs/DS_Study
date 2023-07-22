#include <iostream>

using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @solution-sync:begin
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        // 判断是否存在环路
        while (true){
            if(fast== nullptr || fast->next== nullptr){
                return nullptr;
            }
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                break;
            }
        }

        // fast 记录fast=slow时的node节点
        // 如果存在，查找环路节点
        fast=head;

        while (fast!=slow  ) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};






ListNode *parseListNode(const vector<int> &values) {
    auto *dum = new ListNode(0);
    ListNode *cur = dum;
    for (int v: values) {
        auto *tmp = new ListNode(v);
        cur->next = tmp;
        cur = cur->next;
    }
    ListNode *res = dum->next;
    delete dum;
    return res;
}

#include <sstream>

string toString(ListNode *h) {
    stringstream out;
    out << "[";
    ListNode *c = h;
    while (c) {
        out << c->val;
        if (c->next)
            out << ",";
        c = c->next;
    }
    out << "]";
    return out.str();
}

int main() {
    ListNode *head = parseListNode(vector<int>{3, 2, 0, -4});
    ListNode * cur=head;
    cur->next->next=cur->next;

    auto solution = Solution();
    auto result = solution.detectCycle(head);
    cout << toString(result) << endl;

    return 0;
}
