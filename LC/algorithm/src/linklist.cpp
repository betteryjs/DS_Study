//
// Created by yjs on 2022/4/15.
//

#include <iostream>
#include <vector>


using namespace std;



// 带头节点的单链表
namespace LinklistTest1 {
    typedef int ElemType;

    struct LinkListNode {

        ElemType data;
        LinkListNode *next;

    };

    typedef LinkListNode *LinkList;

    LinkListNode *GetElem(LinkList L, int i) {
        int j = 1;
        LinkListNode *p = L->next;
        if (i == 0) {
            return L;
        }
        if (i < 1) {
            return nullptr;
        }
        while (p != nullptr && j < i) {

            p = p->next;
            j++;

        }
        return p;
    }


    LinkListNode *GetElem2(LinkList head, int i) {
        if(i<0){
            return nullptr;
        }
        LinkListNode * cur=head;
        while (i--){
            cur=cur->next;
        }
        return cur;

    }



    bool InitList(LinkList &L) {

        L = (LinkListNode *) malloc(sizeof(LinkListNode));
        if (L == nullptr) { // 内存不足分配失败
            return false;
        }
        L->next = nullptr; // head 后面没有节点
        return true;
    }

    // 在第i个位置插入元素e

    // 在p节点之后插入元素e
    bool InsertNextNode(LinkListNode *p, const ElemType &e) {

        if (p == nullptr) {
            return false;
        }
        LinkListNode *s = (LinkListNode *) malloc(sizeof(LinkListNode));
        if (s == nullptr) {
            return false;
        }
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;


    }


    // 在p节点之前插入元素e
    bool InsertPriorNode(LinkListNode *p, const ElemType &e) {

        if (p == nullptr) {
            return false;

        }
        // init Node
        LinkListNode *s = (LinkListNode *) malloc(sizeof(LinkListNode));
        if (s == nullptr) {
            return false;
        }
        s->next = p->next;
        p->next = s;
        s->data = p->data;
        p->data = e;
        return true;


    }


    bool ListInsert(LinkList &head, const int &i, const ElemType &e) {
        if (i < 1) {
            return false;
        }
        LinkListNode *cur = head;
        int count = i - 1;
        while (--count) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            return false;
        }
        InsertNextNode(cur, e);

    }


    // 在p节点之前插入节点s
    bool InsertPriorNode(LinkListNode *p, LinkListNode *s) {

        if (p == nullptr || s == nullptr) {
            return false;

        }
        s->next = p->next;
        p->next = s;

        swap(p->data, s->data);
        return true;


    }


    // 按位序删除
    bool ListDelete(LinkList &head, const int &i, ElemType &e) {


        if (i < 1) {
            return false;
        }

        int count = i - 1;
        LinkListNode *cur = head;
        while (--count) {
            cur = cur->next;
        }

        if (cur == nullptr || cur->next == nullptr) {
            // cur== nullptr i 值不合法
            // cur->next== nullptr  i-1 个节点下一个没有节点

            return false;
        }

        LinkListNode *p = cur->next;
        e = p->data;
        cur->next = p->next; // cur->next=cur->next->next
        free(p);
        return true;


    }


    void PrintLinkList(LinkList head){
        LinkListNode* cur=head->next;
        while (cur){
            cout << cur->data<<" ";
            cur=cur->next;


        }
        cout<< endl;

    }


    LinkListNode* ListTailInsert(LinkList&  head,const vector<int> & nums){
        LinkListNode * pos1=head;
        for (const int  & num:nums) {
            LinklistTest1::InsertNextNode(pos1,num);
            pos1=pos1->next;
        }
        return head;
    }



    LinkListNode* ListHeadInsert(LinkList&  head,const vector<int> & nums){
        for (const int  & num:nums) {
            LinkListNode * s=(LinkListNode*) malloc(sizeof(LinkListNode));
            s->data=num;
            s->next=head->next;
            head->next=s;
        }
        return head;
    }



    int GetLength(LinkList head){
        int length=0;
        LinkListNode *cur=head;
        while (cur->next!= nullptr){
            length++;
            cur=cur->next;
        }
        return length;


    }



    LinkListNode* LocateElem(LinkList head,const ElemType & e){
        LinkListNode * cur=head->next;
        while (cur!= nullptr && cur->data!=e){
            cur=cur->next;

        }
        return cur;
    }



//    //    删除指定的节点 p
//    bool DeleteNode(LinkListNode *p) {
//        if (p == nullptr) {
//            return false;
//        }
//        LinkListNode *q = p->next;
//        p->data = p->next->data;
//        p->next = q->next;
//        free(q);
//        return true;
//
//
//    }

}


// 不带头节点的单链表
namespace LinklistTest2 {

    typedef int ElemType;

    struct LinkListNode {

        ElemType data;
        LinkListNode *next;
    };

    typedef LinkListNode *LinkList;

    bool InitList(LinkList &L) {
        L = nullptr;
        return true;
    }


    bool ListInsert(LinkList &head, const int &i, const ElemType &e) {


        if (i < 1) {

            return false;
        }
        if (i == 1) {
            LinkListNode *s = (LinkListNode *) malloc(sizeof(LinkListNode));
            s->data = e;
            s->next = head;
            head = s;
            return true;

        }
        LinkListNode *cur = head;
        int count = i - 2;
        while (--count) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            return false;
        }
        LinkListNode *s = (LinkListNode *) malloc(sizeof(LinkListNode));
        s->data = e;
        s->next = cur->next;
        cur->next = s;
        return true;


    }


}


int main() {
    LinklistTest1::LinkList head;
    LinklistTest1::InitList(head);
    vector<int> nums{1,3,6,8,9};
//    LinklistTest1::ListTailInsert(head,nums);
    LinklistTest1::ListHeadInsert(head,nums);
    LinklistTest1::PrintLinkList(head);
    cout << LinklistTest1::GetElem2(head,2)->data<<endl;
    LinklistTest1::InsertPriorNode(LinklistTest1::GetElem2(head,2),66);

    LinklistTest1::PrintLinkList(head);

    cout << GetLength(head)<<endl;





    return 0;

}




