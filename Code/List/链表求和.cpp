//
// Created by yjs on 2022/2/24.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode *cur = head;
        int carry = 0, sum = 0;
        while (l1 || l2 || carry ){
            sum=0;
           if(l1!= nullptr){
               sum+=l1->val;
               l1=l1->next;
           }
            if(l2!= nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode * tmp=new ListNode(sum % 10);
            carry = sum / 10;
            cur->next=tmp;
            cur=cur->next;








        }
        return head->next;










    }
};


int main() {

    return 0;
}