#include <iostream>

using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @solution-sync:begin
// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // time O(n) space O(1)
        ListNode* pre= nullptr;
        ListNode* cur= head;
        while (cur!= nullptr){
            ListNode* nextTemp = cur->next;
            cur->next=pre;
            pre=cur;
            cur=nextTemp;
        }
        return pre;
    }
};
// @solution-sync:end

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        // time O(n) space O(n)
        if(head== nullptr || head->next== nullptr){
            return head;
        }
        ListNode * ret= this->reverseList(head->next);
        head->next->next=head;
        head->next= nullptr;
        return ret;
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
    ListNode *head = parseListNode(vector<int>{1, 2, 3, 4, 5});

    auto solution = Solution();
    auto result = solution.reverseList(head);
    cout << toString(result) << endl;

    return 0;
}
