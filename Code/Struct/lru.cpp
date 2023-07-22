//
// Created by yjs on 2022/5/23.
//

#include <bits/stdc++.h>


using namespace std;



class  DNode{
public:
    int  key,val;
    DNode * next,* prior;
    DNode(int k,int v) : key(k),val(v){}
};



class DoubleList{

private:
    DNode * head,* tail;
    int size;
public:
    DoubleList(){
        head = new DNode(0,0);
        tail = new DNode(0,0);
        head->next=tail;
        tail->prior=head;
        size=0;

    }

public:

    void  addLast(DNode * node){

        node->prior=tail->prior;
        node->next=tail;
        tail->prior->next=node;
        tail->prior=node;
        size++;
    }

    void remove( DNode * node){

        node->prior->next=node->next;
        node->next->prior=node->prior;
        size--;

    }
    DNode * removeFirst(){
        if(head->next== nullptr){
            return nullptr;
        }
        DNode * first=head->next;
        remove(first);
        return first;

    }
    int getSize(){
        return size;
    }
};

class LRUCache{

private:
    unordered_map<int,DNode* >map;
    DoubleList * cache;
    // 最大长度
    int cap;


private:

    // 将一个key提升为最近使用
    void makeRecently(int key){

        DNode * node=map[key];
        cache->remove(node);
        cache->addLast(node);
    }
    // 添加最近使用的元素
    void  addRecently(int key ,int val){
        DNode * node=new DNode(key,val);
        cache->addLast(node);
        map.insert({key,node});
    }

    // 删除一个key
    void deleteKey(int key){
        DNode * x=map[key];
        cache->remove(x);
        map.erase(key);
    }

    // 删除最长时间未使用的
    void  removeLeastRecently(){

        DNode * deleteNode=cache->removeFirst();
        int deleteKey=deleteNode->key;
        map.erase(deleteKey);



    }







public:
    LRUCache(int capactity){
        this->cap=capactity;
        cache= new DoubleList();

    }

public:

    int get(int key){
        if(map.count(key)==0){
            return -1;
        }
        makeRecently(key);
        return map[key]->val;

    }

    void put(int key,int val){
        if(map.count(key)){
            deleteKey(key);
            addRecently(key,val);
            return ;


        }
        if(cap==cache->getSize()){
            removeLeastRecently();
        }

        addRecently(key,val);

    }




};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
