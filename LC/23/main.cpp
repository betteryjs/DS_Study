#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* n1,ListNode* n2){
            return n1->val>n2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        // 优先级队列，最小堆
        priority_queue<ListNode* ,vector<ListNode *>, cmp> priorityQueue;
        // 将 k 个链表的头结点加入最小堆

        for (ListNode* list : lists) {
            if(list!= nullptr){
                priorityQueue.push(list);
            }

        }
        while (!priorityQueue.empty()){

            // 获取最小节点，接到结果链表中
            ListNode * node=priorityQueue.top();
            priorityQueue.pop();

            cur->next=node;
            if(node->next!= nullptr){

                priorityQueue.push(node->next);


            }
            cur=cur->next;
         }
        return dummy->next;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
