#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> minStack;
    stack<int> returnStack;

public:
    /** initialize your data structure here. */
    MinStack() {


    }

    void push(int x) {
        returnStack.push(x);
       if(minStack.empty() || minStack.top() >=x){
           minStack.push(x);
       }


    }

    void pop() {
       if(minStack.top()==returnStack.top()){

           minStack.pop();
           returnStack.pop();

       }else{
           returnStack.pop();

       }

    }

    int top() {

        return returnStack.top();

    }

    int min() {

        return minStack.top();
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
