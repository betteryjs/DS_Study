//
// Created by yjs on 2022/2/24.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class TripleInOne {
private:
    int *stack;
    int N = 3;
    int top[3]={0,0,0};
    int stackSize;
public:
    TripleInOne(int stackSize) {
        stack = new int[stackSize * N];
        this->stackSize = stackSize;

        for (int i = 0; i < N; i++) {
            top[i] = i * this->stackSize;
        }


    }

    void push(int stackNum, int value) {
        int idx = top[stackNum];
        if (idx < (stackNum + 1) * stackSize) {
            stack[idx] = value;
            top[stackNum]++;
        }


    }

    int pop(int stackNum) {
        if (this->isEmpty(stackNum)) {
            return -1;
        }
        int idx = top[stackNum];
        top[stackNum]--;
        return stack[idx - 1];




    }

    int peek(int stackNum) {
        if (this->isEmpty(stackNum)) {
            return -1;
        }
        int idx = top[stackNum];
        return stack[idx - 1];



    }

    bool isEmpty(int stackNum) {
        return top[stackNum] == stackNum * this->stackSize;

    }




};

int main() {

    return 0;
}