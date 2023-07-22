//
// Created by yjs on 2022/4/15.
//


#include <iostream>
#include <vector>


using namespace std;


namespace DLinkListTest {

    typedef int ElemType;
    struct DNode {
        ElemType data;
        DNode *prior, *next;
    };
    typedef DNode *DLinkList;


    bool InitDLinkList(DLinkList &) ;
    bool Empty(const DLinkList &) ;
    bool InsertTailDNode(DLinkList &,const vector<int> & );
    bool InsertNextDNode(DNode *, DNode *) ;
    bool InsertNextDNode(DNode *, const ElemType & );
    bool DeleteNextDNode(DNode * );
    void DestoryDLinkList(DLinkList & );
    void PrintDLinkList(const DLinkList & );








    bool InitDLinkList(DLinkList &L) {
        L = (DNode *) malloc(sizeof(DNode));
        if (L == nullptr) {
            return false;
        }
        L->prior = nullptr;
        L->next = nullptr;
        return true;
    }

    bool Empty(const DLinkList &L) {
        if (L->next == nullptr) {
            return true;
        }
        return false;
    }


    bool InsertTailDNode(DLinkList &L,const vector<int> & nums){

        DNode * pos1=L;
        for (const int  & num:nums) {
            InsertNextDNode(pos1,num);
            pos1=pos1->next;
        }
        return L;




    }


    // 在节点p之后插入s节点
    bool InsertNextDNode(DNode *p, DNode *s) {
        if (p == nullptr || s == nullptr) {
            return false;
        }
        s->next = p->next;
        if (p->next != nullptr) {
            p->next->prior = s;

        }
        s->prior = p;
        p->next = s;

        return true;


    }



    bool InsertNextDNode(DNode *p, const ElemType & e) {
        if (p == nullptr ) {
            return false;
        }
        DNode * s= (DNode * ) malloc(sizeof(DNode));
        s->data=e;
        s->next = p->next;
        if (p->next != nullptr) {
            p->next->prior = s;

        }
        s->prior = p;
        p->next = s;

        return true;


    }


    // 删除p的后继节点

    bool DeleteNextDNode(DNode * p){
        if (p== nullptr){
            return false;
        }
        DNode * cur=p->next;
        if(cur== nullptr){
            return false;
        }
        p->next=cur->next;
        if(cur->next!= nullptr){
            cur->next->prior=p;
        }
        free(cur);
    }

    void DestoryDLinkList(DLinkList & L){

        while (L->next!= nullptr){
            DeleteNextDNode(L);
        }
        free(L);
        L= nullptr;


    }


    void  PrintDLinkList(const DLinkList & L){
        DNode* cur=L->next;
        while (cur){
            cout << cur->data<<" ";
            cur=cur->next;
        }
        cout<< endl;
    }




}


int main() {
    DLinkListTest::DLinkList head;
    DLinkListTest::InitDLinkList(head);
    vector<int> nums{1,66,99,56};


    DLinkListTest::InsertTailDNode(head,nums);
    DLinkListTest::PrintDLinkList(head);


    return 0;
}