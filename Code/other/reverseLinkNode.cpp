//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ReverseList {
public:
    class Node {
    public:
        int value;
        Node *next;

        Node(int data) {
            value = data;
        }
    };


    class DoubleNode {
    public:

        int value;
        DoubleNode *last;
        DoubleNode *next;

        DoubleNode(int data) {
            value = data;
        }
    };

    //  head
    //   a    ->   b    ->  c  ->  null
    //   c    ->   b    ->  a  ->  null
public:


    Node *reverseLinkedList(Node *head) {
        Node *pre = nullptr;
        Node *next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }


    DoubleNode *reverseDoubleList(DoubleNode *head) {
        DoubleNode *pre = nullptr;
        DoubleNode *next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = pre;
            head->last = next;
            pre = head;
            head = next;
        }
        return pre;
    }

};


int main() {

    return 0;
}