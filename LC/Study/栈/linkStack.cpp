//
// Created by yjs on 2022/5/17.
//

//
// Created by yjs on 2022/5/17.
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



namespace HaveNodeHead{


    bool initStack(ListNode * head){
        head =new ListNode(-1);
        head->next= nullptr;


    }

    bool insertNode(ListNode * tail,int x){
        if(tail== nullptr){
            return false;
        }
        ListNode * node=new ListNode(x);
        node->next=tail->next;
        tail->next=node;
        return true;

    }

    bool push(ListNode * head,int x){
        return insertNode(head,x);
    }

    bool top(ListNode * head,int x){
        if(head->next!= nullptr){
            x= head->next->val;
            return true;
        }else{
            return false;
        }


    }
    int pop(ListNode * head){
        if(head->next!= nullptr){
            ListNode * tmp=head->next;
            head->next=tmp->next;
            int res=tmp->val;
            delete tmp;

            return res;
        }else{
            return -1;
        }

    }

    bool isempty(ListNode * head){
        return head->next == nullptr;
    }




}

int main(){
    ListNode * linkStack;
    vector<int> input{1,2,3,4,5,6,7,8,9};
    cout << "isempty : "<< HaveNodeHead::isempty(linkStack) <<endl;
    for (int c: input) {
        HaveNodeHead::push(linkStack,c);


    }
    cout << "isempty : "<< HaveNodeHead::isempty(linkStack) <<endl;


    for (int i = 0; i < 9; ++i) {
        HaveNodeHead::pop(linkStack);
        int x=0;
        cout << HaveNodeHead::top(linkStack,x)<<endl;

        cout << "isempty : "<< HaveNodeHead::isempty(linkStack) <<endl;

    }








    return 0;


};
