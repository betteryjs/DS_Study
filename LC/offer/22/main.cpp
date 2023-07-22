struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @solution-sync:begin
#include <iostream>

using namespace std;
#include <vector>


// @solution-sync:begin
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * fast=head;
        ListNode * slow=head;
        while (k--){
            fast=fast->next;
        }
        while(fast != nullptr) {//同时移动，直到 p == nullptr
            slow = slow->next;
            fast = fast->next;
        }
        // slow is k node


        return slow;


    }
};
// @solution-sync:end

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
    int k = 2;

    auto solution = Solution();
    auto result = solution.getKthFromEnd(head, k);
    cout << toString(result) << endl;

    return 0;
}