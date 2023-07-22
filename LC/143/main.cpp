#include <iostream>


/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

private:


    ListNode * getMid(ListNode * head){
        if(head== nullptr  || head->next== nullptr){
            return head;
        }
        ListNode * fast=head,* slow=head;
        while (fast!= nullptr && fast->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }


    ListNode * reverse(ListNode * head){
        if(head== nullptr || head->next== nullptr){
            return head;
        }
        ListNode * prev= nullptr;
        ListNode * cur=head;
        while (cur!= nullptr){
            ListNode * nextCur=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextCur;
        }
        return prev;


    }


public:
    void reorderList(ListNode *head) {
        if(head== nullptr || head->next== nullptr){
            return;
        }

        ListNode * mid= getMid(head);
        ListNode * head2=mid->next;
        mid->next= nullptr;
        ListNode * newHead= reverse(head2);
        ListNode * dummyHead=new ListNode(-1);
        ListNode * cur3=dummyHead;
        ListNode * cur1=head;
        ListNode * cur2=newHead;
        while (cur1 != nullptr && cur2!= nullptr){

            cur3->next=cur1;
            cur1=cur1->next;
            cur3=cur3->next;

            cur3->next=cur2;
            cur2=cur2->next;
            cur3=cur3->next;
        }



        cur3->next=cur1 == nullptr ? cur2:cur1;


        head=dummyHead->next;






    }
};


class Solution2 {
private:
    ListNode * getMid(ListNode * head){
        if(head== nullptr  || head->next== nullptr){
            return head;
        }
        ListNode * fast=head,* slow=head;
        while (fast!= nullptr && fast->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode * reverse(ListNode * head){
        if(head== nullptr || head->next== nullptr){
            return head;
        }
        ListNode * prev= nullptr;
        ListNode * cur=head;
        while (cur!= nullptr){
            ListNode * nextCur=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextCur;
        }
        return prev;
    }
    ListNode * margeList(ListNode * l1,ListNode*  l2){
        ListNode* tmpl1;
        ListNode* tmpl2;
        while (l1!= nullptr && l2!= nullptr){
            tmpl1=l1->next;
            tmpl2=l2->next;
            l1->next=l2;
            l1=tmpl1;
            l2->next=l1;
            l2=tmpl2;
        }
        return l1;
    }

public:
    void reorderList(ListNode *head) {
        if(head== nullptr || head->next== nullptr){
            return;
        }
        ListNode * mid= getMid(head);
        ListNode * l2=mid->next;
        ListNode * l1=head;
        mid->next= nullptr;
        l2= reverse(l2);
        margeList(l1,l2);
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
