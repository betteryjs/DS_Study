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
    int kthToLast(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        while (k--){
            fast=fast->next;
        }
        while (fast!= nullptr){

            fast=fast->next;
            slow=slow->next;
        }
        return slow->val;


    }
};
int main() {

    return 0;
}