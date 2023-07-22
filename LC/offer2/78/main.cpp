#include <bits/stdc++.h>


using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
private:

    struct  cmp{

        bool operator () (ListNode *a,ListNode *b){
            return a->val>b->val;
        }

    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {


        priority_queue<ListNode * ,vector<ListNode * >,cmp> priorityQueue;


        for (ListNode* list:lists) {
            if(list!= nullptr){

                priorityQueue.push(list);
            }
        }


        ListNode *dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!priorityQueue.empty()){


            ListNode * node = priorityQueue.top(); //top指针指向第一个出队的元素（最小的）

            priorityQueue.pop();

            if (node->next != nullptr) {
                priorityQueue.push(node->next);
            }
            cur->next = node;
            cur = cur->next;


        }
        return dummy->next;


    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
