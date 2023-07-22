#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:


    int evalRPN(vector<string> &tokens) {
        stack<int> stackToken;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            string &token = tokens[i];
            if (isNumber(token)) {
                stackToken.push(atoi(token.c_str()));
            } else {
                // is - + * /
                int rightNumber = stackToken.top();
                stackToken.pop();
                int leftNumber = stackToken.top();
                stackToken.pop();
                switch (token[0]) {

                    case '+':
                        stackToken.push(leftNumber + rightNumber);
                        break;
                    case '-':
                        stackToken.push(leftNumber - rightNumber);
                        break;
                    case '*':
                        stackToken.push(leftNumber * rightNumber);
                        break;
                    case '/':
                        stackToken.push(leftNumber / rightNumber);
                        break;

                }


            }

        }
        return stackToken.top();
    }


    int preRPN(vector<string> &tokens) {
        stack<int> stackToken;
        int n = tokens.size();
        for (int i = n - 1; i >= 0; --i) {
            string &token = tokens[i];
            if (isNumber(token)) {
                stackToken.push(atoi(token.c_str()));
            } else {
                // is - + * /
                int leftNumber = stackToken.top();
                stackToken.pop();
                int rightNumber = stackToken.top();
                stackToken.pop();
                switch (token[0]) {

                    case '+':
                        stackToken.push(leftNumber + rightNumber);
                        break;
                    case '-':
                        stackToken.push(leftNumber - rightNumber);
                        break;
                    case '*':
                        stackToken.push(leftNumber * rightNumber);
                        break;
                    case '/':
                        stackToken.push(leftNumber / rightNumber);
                        break;

                }


            }


        }
        return stackToken.top();
    }



    vector<string> toEvalRPN(vector<string> &tokens) {
        stack<char> stackToken;
        vector<string> res;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {

            string &token = tokens[i];

            if (isNumber(token)) {

                res.push_back(token);

            } else {
                // is - + * / ( )
                if (stackToken.empty())            //栈空则入站
                    stackToken.push(token[0]);
                else if (token[0] == '(') {
                    //左括号入栈
                    stackToken.push(token[0]);

                } else if (token[0] == ')') {
                    //如果是右括号，只要栈顶不是左括号，就弹出并输出
                    while (stackToken.top() != '(') {
                        res.emplace_back(1, stackToken.top());
                        stackToken.pop();
                    }
                    stackToken.pop();                 //弹出左括号，但不输出

                } else {
                    while (prio(token[0]) <= prio(stackToken.top()))   //栈顶优先级大于等于当前运算符，则输出
                    {
                        res.emplace_back(1, stackToken.top());

                        stackToken.pop();
                        if (stackToken.empty())      //栈为空，停止
                            break;
                    }
                    stackToken.push(token[0]);   //把当前运算符入栈
                }


            }


        }
        while (!stackToken.empty())        //最后，如果栈不空，则弹出所有元素并输出
        {
            res.emplace_back(1, stackToken.top());
            stackToken.pop();
        }
        return res;
    }


    bool isNumber(const string &token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/" || token == "(" || token == ")");
    }

    int prio(const char &op) {
        //给运算符优先级排序
        int priority;
        if (op == '*' || op == '/')
            priority = 2;
        if (op == '+' || op == '-')
            priority = 1;
        if (op == '(')
            priority = 0;
        return priority;
    }

};

int main() {

    vector<string> tokens = {"2", "1", "+", "3", "*"}; // 后缀
    vector<string> tokens2 = {"*", "+", "1", "2", "3"}; // 前缀
    vector<string> tokens3 = {"1", "+", "2", "*", "3", "+", "(", "25", "*", "3", "+", "4", ")", "*", "2"}; // 中缀

    Solution go;
    cout << go.evalRPN(tokens) << endl;
    cout << go.preRPN(tokens2) << endl;
    auto res = go.toEvalRPN(tokens3);
    for (auto c: res) {
        cout << c << " ";
    }
    cout << endl;


    return 0;
}
