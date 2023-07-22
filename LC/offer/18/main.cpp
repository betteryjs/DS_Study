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
    ListNode* deleteNode(ListNode* head, int val) {

        if(head->val==val){
            return head->next;
        }
        ListNode *pre = head, *cur = head->next;

        while(cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        if(cur != nullptr) {
            pre->next = cur->next;
        }
        return head;








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
    ListNode *head = parseListNode(vector<int>{4, 5, 1, 9});
    int val = 5;

    auto solution = Solution();
    auto result = solution.deleteNode(head, val);
    cout << toString(result) << endl;

    return 0;
}
