//
// Created by yjs on 23-7-29.
//
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution{
public:
    ListNode *  deleteListNode (ListNode* head){
        ListNode* cur= head->next;
        ListNode* pre=head; // pre指向头结点
        ListNode* min=cur; // 假设第一个结点为最小值的结点
        while (cur->next!= nullptr){
            if(cur->next->val < min->val){
                pre=cur;
                min=cur->next;
            }
            cur=cur->next;
        }
        pre->next=min->next; // 从链表上删除最小值结点
//        free (min);
        return head;
    }





public:

    ListNode * selectSort(ListNode* head){

        ListNode * dummyHead= new ListNode(-1);
        ListNode * dummyCurser=dummyHead;
        while (head->next!= nullptr){
            ListNode* cur= head->next;
            ListNode* pre=head; // pre指向头结点
            ListNode* min=cur; // 假设第一个结点为最小值的结点
            while (cur->next!= nullptr){
                if(cur->next->val < min->val){
                    pre=cur;
                    min=cur->next;
                }
                cur=cur->next;
            }
            pre->next=min->next; // 从链表上删除最小值结点
            dummyCurser->next=min;
            dummyCurser=dummyCurser->next;

        }


        dummyCurser->next= nullptr;
        return dummyHead->next;



    }


};







string ppint(ListNode * head){
    ListNode * cur=head;
    string res="";
    int count=0;
    while (cur!= nullptr){
        count++;
        res= res+to_string(cur->val)+" ";
        cur=cur->next;
    }
    return " ["+to_string(count)+"] "+ res+"\n";


}

int main() {

    vector<int> nums{ 12,25, 36, 17, 25, 56,1};
    ListNode* head=new ListNode(-1);
    ListNode * cur=head;

    for (int i = 0; i < nums.size(); ++i) {
        cur->next=new ListNode(nums[i]);
        cur=cur->next;
    }
    cout << ppint(head->next)<<endl;
    Solution solution;
//    for (int i = 0; i < 7; ++i) {
//        head=solution.deleteListNode(head);
//        cout << ppint(head->next)<<endl;
//    }
    ListNode * res=solution.selectSort(head);
    cout << ppint(res)<<endl;
















}


