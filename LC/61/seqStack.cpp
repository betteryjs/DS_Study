//
// Created by yjs on 2022/5/17.
//

#include <bits/stdc++.h>

using namespace std;


namespace Top0 {
    template<class T, int size>
    class SeqStack {
    private:
        int top = -1;
        int data[size];
    public:

        bool getTop(T &x) {
            if (top == -1) {
                return false;
            } else {
                x = data[top];
            }
            return true;
        }

        bool isEmpty() {
            return (top == -1 ? true : false);
        }

        bool pop(T &x) {
            if (isEmpty()) {
                return false;
            } else {
                x = data[top--];

            }
            return true;
        }

        bool push(T &x) {
            if (top == size - 1) {
                return false;
            } else {
                data[++top] = x;
            }
            return true;


        }


    };


}


namespace Top1 {
    template<class T, int size>
    class SeqStack {
    private:
        int top = 0;
        int data[size];
    public:

        bool getTop(T &x) {

            if (top == 0) {
                return false;
            } else {
                x = data[top-1];
            }
            return true;
        }

        bool isEmpty() {
            return (top == 0 ? true : false);
        }

        bool pop(T &x) {
            if (isEmpty()) {
                return false;
            } else {
                x = data[--top];

            }
            return true;
        }

        bool push(T &x) {
            if (top == size) {
                return false;
            } else {
                data[top++] = x;
            }
            return true;


        }


    };


}


int main() {
    Top0::SeqStack<int, 20> seqStack;
    int x = 22;
    int tmp = 0;
    int res;

    cout << " status push : " << seqStack.push(x) << endl;

    cout << " status top : " << seqStack.getTop(tmp) << endl;
    cout << "  top : " << tmp << endl;
    cout << " status push : " << seqStack.pop(res) << endl;
    cout << res << endl;


    Top1::SeqStack<int, 20> seqStack2;
    vector<int> ans{1,2,3,4};
    for ( int  c: ans) {
        seqStack2.push(c);

    }
    int res2;
    cout << " status top : " << seqStack2.getTop(res2) << endl;
    cout << "  top : " << res2 << endl;
    cout << " status push : "<<seqStack2.pop(res) <<endl;
    cout << res<<endl;
    cout << " status top : " << seqStack2.getTop(res2) << endl;
    cout << "  top : " << res2 << endl;










    return 0;
};
