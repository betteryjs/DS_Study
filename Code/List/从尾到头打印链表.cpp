//
// Created by yjs on 2022/5/14.
//
#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// stack
class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        stack<ListNode *> stackNode;
        vector<int> ans;
        ListNode *cur = head;
        while (cur != nullptr) {
            stackNode.push(cur);
            cur = cur->next;

        }
        while (!stackNode.empty()) {
            ans.push_back(stackNode.top()->val);
            stackNode.pop();
        }
        return ans;

    }
};

// 递归法
class Solution2 {
private:

    vector<int> ans;

public:
    vector<int> reversePrint(ListNode *head) {

        reverse(head);
        return ans;


    }
    void  reverse(ListNode * head){
        if(head== nullptr){
            return;
        }
        reverse(head->next);
        ans.push_back(head->val);


    }




};


