//
// Created by yjs on 2022/4/12.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// 暴力递归 time O(2^n)
class Solution {
    // fib(n)= fib(n-1)+fib(n-2)
public:
    int fib(int n) {
        if(n<2){
            return n;
        }
        return fib(n - 1) + fib(n - 2);


    }
};


// 带备忘录的递归解法 time O(n)
class Solution2 {
    // fib(n)= fib(n-1)+fib(n-2)
public:
    int fib(int n) {
        if(n<1){
            return 0;
        }
        vector<int> memo(n + 1, 0);
        return helper(memo,n);
    }
    int helper(vector<int>& memo,int n){

        if (n == 1 || n == 2) return 1;
        if(memo[n]!=0){
            return memo[n];
        }
        memo[n]= helper(memo,n-1)+ helper(memo,n-2);
        return memo[n];
    }
};

// dp 数组的迭代（递推）解法
class Solution3 {
    // fib(n)= fib(n-1)+fib(n-2)
public:
    int fib(int n) {
        vector<int> dp(n + 1, 0);
        dp[0]=0;dp[1]=1;
        for (int i = 2; i <= n; ++i) {
            dp[i]=dp[i-1]+dp[i-2];

        }
        return dp[n];
    }
};


// F(n)=F(n-1)+F(n-2)
// F(n)=c1*x1^n + c2*x2^n
// c1=1/sqrt(5) c2=-(1/sqrt(5))

// 通项公式
class Solution4 {
    // fib(n)= fib(n-1)+fib(n-2)
public:
    int fib(int n) {
        double sqrt5=sqrt(5);
        double fibN= pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN/sqrt5);
    }
};


class Solution5 {
    // fib(n)= fib(n-1)+fib(n-2)
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            // base case
            return n;
        }
        // 分别代表 dp[i - 1] 和 dp[i - 2]
        int dp_i_1 = 1, dp_i_2 = 0;
        for (int i = 2; i <= n; i++) {
            // dp[i] = dp[i - 1] + dp[i - 2];
            int dp_i = dp_i_1 + dp_i_2;
            // 滚动更新
            dp_i_2 = dp_i_1; // dp[i-2]=dp[i-1]
            dp_i_1 = dp_i;   // dp[i-1]= dp[i]
        }
        return dp_i_1;
    }
};







int main(){


    Solution3 go3;
    cout << go3.fib(3)<<endl;


    return 0;
}
