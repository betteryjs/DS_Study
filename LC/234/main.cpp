#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// vector
class Solution {
public:
    bool isPalindrome(ListNode *head) {

        vector<int> LinkNodeList;
        ListNode *cur = head;
        while (cur) {
            LinkNodeList.push_back(cur->val);
            cur = cur->next;
        }
        for (int i = 0, j = LinkNodeList.size() - 1; i < j; ++i, --j) {
            if (LinkNodeList[i] != LinkNodeList[j]) {
                return false;
            }

        }
        return true;


    }
};


class Solution2 {
// space O(n)
public:

    /* 倒序打印单链表中的元素值 */
    void traverse(ListNode *head) {
        if (head == nullptr) return;
        //     前序遍历代码
        traverse(head->next);
        // 后序遍历代码
        cout << head->val << endl;
    }
};


class Solution3 {
    // 递归栈
private:
    ListNode *left;
public:
    bool isPalindrome(ListNode *head) {
        this->left = head;
        return traverse(head);

    }

    // 回文判断
    bool traverse(ListNode *right) {
        if (right == nullptr) {
            return true;
        }
        // 前序遍历
        bool res = traverse(right->next);
        res = res && (right->val == left->val);
        left = left->next;
        return res;


    }
};


class Solution4 {
    //

private:

    ListNode *reverseLinkList(ListNode *head) {

        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *nextCur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextCur;
        }
        return prev;

    }


public:
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head, *left = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow is the mid of the Link list
        ListNode *right = reverseLinkList(slow);
        while (right != nullptr) {
            if (left->val != right->val) {


                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;


    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
