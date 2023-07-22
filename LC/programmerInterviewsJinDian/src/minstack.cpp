//
// Created by yjs on 2022/2/24.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class MinStack {
private:
    stack<int> x_stack;
    stack<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);

    }

    void push(int x) {
        x_stack.push(x);
        minStack.push(min(minStack.top(), x));


    }

    void pop() {
        x_stack.pop();
        minStack.pop();
    }

    int top() {
        return x_stack.top();

    }

    int getMin() {
        return minStack.top();

    }
};


int main() {

    return 0;
}