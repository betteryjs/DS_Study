#include <iostream>
#include <bits/stdc++.h>

using namespace std;




// 差分数组工具类
class Difference {
    // 差分数组
private:
    vector<int> diff;

    /* 输入一个初始数组，区间操作将在这个数组上进行 */
public:
    Difference(const  vector<int> &  nums) {
        diff.resize(nums.size());
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i, j] 增加 val（可以是负数）*/
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    /* 返回结果数组 */
    vector<int> result() {
        vector<int> res(diff.size());
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        Difference * df = new Difference(nums);
        for (auto booking : bookings) {

            int i = booking[0]-1;
            int j = booking[1]-1;
            int val = booking[2];
            df->increment(i, j, val);
        }
        return df->result();







    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
