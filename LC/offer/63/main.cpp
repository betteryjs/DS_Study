#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[a][a] 第a天买第a天卖
        int cost = INT32_MAX, profit = 0;
        for(int price : prices) {
            cost =min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;



    }
};


int main() {
    return 0;
}
