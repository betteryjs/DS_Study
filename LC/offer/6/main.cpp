#include <iostream>
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> Stack;
        vector<int> ans;
        while (head!= nullptr){
            Stack.push(head->val);
            head=head->next;

        }
        while (!Stack.empty()){
            ans.push_back(Stack.top());
            Stack.pop();
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* currNode = head;
        int len=0;
        while(currNode!=nullptr){
            currNode=currNode->next;
            len++;
        }
        vector<int> ans(len);
        for (int i = len - 1; i >= 0; --i) {
            ans[i] = head->val;
            head = head->next;
        }
        return ans;


    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
