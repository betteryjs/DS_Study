#include <bits/stdc++.h>


using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return  NULL;
        }
        queue<Node * > queueNodes;
        queueNodes.push(root);
        while (!queueNodes.empty()){
            int sz=(int) queueNodes.size();
            Node * prev=NULL;
            for (int i = 0; i < sz; ++i) {
                Node * cur=queueNodes.front();
                queueNodes.pop();
                if(prev!=NULL){
                    prev->next=cur;
                }
                prev=cur;

                if(cur->left!=NULL){
                    queueNodes.push(cur->left);
                }
                if(cur->right!=NULL){
                    queueNodes.push(cur->right);
                }


            }



        }
        return root;




    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
