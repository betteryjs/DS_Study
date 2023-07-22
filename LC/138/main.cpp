#include <bits/stdc++.h>


using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// unordered_map
class Solution {


public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node *, Node *> Map;

        auto cur = head;
        while (cur != nullptr) {

            Map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr) {

            Map[cur]->next = Map[cur->next];
            Map[cur]->random = Map[cur->random];

            cur = cur->next;
        }
        return Map[head];


    }
};



// unordered_map2


class Solution2 {


private:

    unordered_map<Node *, Node *> Map;
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return head;
        }
        if (!Map.count(head)) {

            Node *newNode = new Node(head->val);
            Map[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);

        }
        return Map[head];


    }


};


class Solution3 {


public:

    Node *copyRandomList(Node *head) {
        if(head== nullptr){
            return nullptr;
        }

        Node * cur=head;
        while (cur!= nullptr){
            Node * newNode=new Node(cur->val);
            newNode->next=cur->next;
            cur->next=newNode;
            cur=newNode->next;
        }

        cur=head;
        while (cur!= nullptr){
            if(cur->random!= nullptr){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }

        // cut list
        Node * dummyHead=new Node(-1);
        Node * dummyCur=dummyHead;
        cur=head;
        while (cur!= nullptr){


            dummyCur->next=cur->next;
            dummyCur=dummyCur->next;
            cur->next=dummyCur->next;
            cur=cur->next;
        }
        return dummyHead->next;









    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
