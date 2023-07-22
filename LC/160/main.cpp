#include <iostream>
#include <unordered_set>


using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


// unordered_set
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        unordered_set<ListNode *> visited;
        ListNode *tmp = headA;
        while (tmp) {
            visited.insert(tmp);
            tmp = tmp->next;
        }
        tmp = headB;
        while (tmp) {
            if (visited.count(tmp)) {
                return tmp;
            }
            tmp = tmp->next;


        }
        return nullptr;


    }
};



class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * cur1=headA,*cur2=headB;
        while (cur1!=cur2){
            cur1=cur1!= nullptr ? cur1->next:headB;
            cur2=cur2!= nullptr ? cur2->next:headA;


        }
        return cur1;





    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
