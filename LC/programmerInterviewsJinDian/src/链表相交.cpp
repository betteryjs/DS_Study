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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * curA=headA;
        ListNode * curB=headB;

        while (curA!= nullptr && curB!= nullptr){

            if(curA->val==curB->val){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;


        }
        return nullptr;




    }
};

int main() {

    return 0;
}