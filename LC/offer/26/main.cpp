#include <iostream>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        // BFS A
        return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));

    }

    bool recur( TreeNode *A, TreeNode *B){
        if(B == nullptr) return true;
        if(A == nullptr || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
