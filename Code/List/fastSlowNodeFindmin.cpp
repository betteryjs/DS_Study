//
// Created by yjs on 2022/5/12.
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


class FastSlowNode {
public:


    // 奇数个数找到中点 偶数个数找到中点的前一个节点
    ListNode * findMid(ListNode * head){
        ListNode * fast= head,* slow=head;
        while (fast != nullptr && fast->next != nullptr){

            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode * findMid2(ListNode * head){
        ListNode * fast= head->next,* slow=head;
        while (fast != nullptr && fast->next != nullptr){

            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }



};


class BuildList{
private:


    vector<int> nums;

private:



    bool InsertNextNode(ListNode *p, const int &e) {

        if (p == nullptr) {
            return false;
        }
        ListNode *s = new ListNode(e);
        s->next = p->next;
        p->next = s;
        return true;
    }
    ListNode * head=new ListNode(-1);



public:

    BuildList(const vector<int> & nums):nums(nums){
        ListNode * cur=this->head;

        ListTailInsert(cur, nums);




    }

    ListNode *ListTailInsert(ListNode *head, const vector<int> &nums) {
        ListNode *pos1 = head;
        for (const int &num: nums) {
            InsertNextNode(pos1, num);
            pos1 = pos1->next;
        }
        return head;
    }


    void PrintLinkList(ListNode *head) {
        ListNode *cur = head->next;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;


        }
        cout << endl;

    }


   ListNode * getHead(){

        return  this->head;

    }



};







int main() {
    vector<int> nums{1, 25, 26, 23,17};
    BuildList  buildList(nums);
    FastSlowNode* fastSlowNode=new FastSlowNode();
    ListNode * res=fastSlowNode->findMid(buildList.getHead());
    ListNode * res2=fastSlowNode->findMid2(buildList.getHead());
    buildList.PrintLinkList(buildList.getHead());

    cout << res->val<<endl;
    cout << res2->val<<endl;





}