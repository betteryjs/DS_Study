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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 迭代
        ListNode* ans= new ListNode(0);;
        ListNode* cur= ans;
        while (l1!= nullptr && l2!= nullptr){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next = l1 != nullptr ? l1 : l2;
        return ans->next;







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
    ListNode *l1 = parseListNode(vector<int>{1, 2, 4});
    ListNode *l2 = parseListNode(vector<int>{1, 3, 4});

    auto solution = Solution();
    auto result = solution.mergeTwoLists(l1, l2);
    cout << toString(result) << endl;

    return 0;
}
