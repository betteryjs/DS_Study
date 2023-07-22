#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy=new ListNode(0),*cur=dummy;
        ListNode * cur1=list1,*cur2=list2;
        while (cur1!= nullptr && cur2!= nullptr){
            if(cur1->val<=cur2->val){

                cur->next=cur1;
                cur1=cur1->next;


            }else{
                cur->next=cur2;
                cur2=cur2->next;
            }
            cur=cur->next;
        }
        if(cur1!= nullptr){

            cur->next=cur1;
        }
        if(cur2!= nullptr){

            cur->next=cur2;

        }

        return dummy->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
