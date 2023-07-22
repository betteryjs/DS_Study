//
// Created by yjs on 2022/1/6.
//
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {
    }

    void appendTail(int value) {
            stack1.push(value);
    }
    int deleteHead() {
        if(!stack2.empty()){
            int tmp=stack2.top();
            stack2.pop();
            return tmp;
        }
        if(stack1.empty()){
            return -1;
        }
        while(!stack1.empty()){ // 1->2
            int tmp=stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int tmp=stack2.top();
        stack2.pop();
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
int main(){
    CQueue* obj = new CQueue();
    vector<string> str{"CQueue","appendTail","deleteHead","deleteHead"};
    vector<vector<int>> conf{{},{3},{},{}};
    vector<int> res;
    auto conf_deg=conf.begin();
    for(auto s:str){
        if(s=="CQueue"){
            CQueue* obj = new CQueue();
            conf_deg++;
            res.emplace_back(0);
        } else if(s=="appendTail"){
            obj->appendTail((*conf_deg)[0]);
            res.emplace_back(0);
        }else if(s=="deleteHead"){
            int param_2=obj->deleteHead();
            res.emplace_back(param_2);
        }

    }
    delete obj;
    for_each(res.begin(),res.end(),[](auto &c){cout<< c<< " ";});

    return 0;

}