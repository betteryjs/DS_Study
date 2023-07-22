//
// Created by yjs on 2022/4/12.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


// 暴力递归
class Solution {

private:
    vector<int> coins;
public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins=coins;
        return dp(amount);
    }
    // 定义：要凑出金额 n，至少要 dp(coins, n) 个硬币
    int dp(int amount) {

        // base case
        if(amount==0) return 0;
        if(amount<0) return -1;


        // 做选择，选择需要硬币最少的那个结果
        int res=INT_MAX;
        for (int coin : this->coins) {
            // 计算子问题的结果
            int subProblem = dp(amount - coin);
            // 子问题无解则跳过
            if (subProblem == -1) continue;
            res=min(res,subProblem+1);
        }
        return res == INT_MAX ? -1:res;
    }
};


// 带备忘录的递归 time O(k*n) 目标金额为 n，给定的硬币个数为 k
class Solution2 {

private:
    vector<int> coins;
    vector<int> memo;

public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins=coins;
        this->memo.resize(amount);
        return dp(amount);
    }

    // 定义：要凑出金额 n，至少要 dp(coins, n) 个硬币
    int dp(int amount) {

        // base case
        if(amount==0) return 0;
        if(amount<0) return -1;

        // find the memo
        if(memo[amount-1]!=0){
            return memo[amount-1];
        }



        // 做选择，选择需要硬币最少的那个结果
        int res=INT_MAX;

        for (int coin : this->coins) {
            // 计算子问题的结果
            int subProblem = dp(amount - coin);
            // 子问题无解则跳过
            if (subProblem == -1) continue;
            res=min(res,subProblem+1);
        }
        memo[amount-1]=res == INT_MAX ? -1:res;

        return memo[amount-1];
    }
};




// dp
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for(const int & coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};









int main(){
    Solution3 go;
    vector<int> cons{1,2,5};
    cout << go.coinChange(cons,11)<<endl;


    return 0;
}