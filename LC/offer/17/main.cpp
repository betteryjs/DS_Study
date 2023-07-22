#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

    string res;
    int count = 0, n;
    string loop{"0123456789"};
    char *num;
public:
    string printNumbers(int n) {
        this->n = n;
        num=new char[n]; // 定义长度为 n 的字符列表
        dfs(0); // 开启全排列递归
        res.pop_back(); // 删除最后多余的逗号
        return res; // 转化为字符串并返回
    }
    void dfs(int x) {
        if(x == n) { // 终止条件：已固定完所有位
            cout << num<<endl;
            res+=string (num) + ","; // 拼接 num 并添加至 res 尾部，使用逗号隔开
            return;
        }
        for(char i : loop) { // 遍历 ‘0‘ - ’9‘
            num[x] = i; // 固定第 x 位为 i
            dfs(x + 1); // 开启固定第 x + 1 位
        }
    }
};


int main() {
    Solution go;
    auto c=go.printNumbers(2);
    cout << c<<endl;
    return 0;
}
