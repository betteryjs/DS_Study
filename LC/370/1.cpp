//
// Created by yjs on 2022/4/17.
//

#include <bits/stdc++.h>

using namespace std;

// 差分数组工具类
class Difference {

private:
    vector<int> diff;

    /* 输入一个初始数组，区间操作将在这个数组上进行 */
public:
    Difference(const vector<int> &nums) {

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

    vector<int> getModifiedArray(int length, vector<vector<int>> updates) {

        vector<int> nums(length);
        Difference * df = new Difference(nums);
        for (vector<int> update : updates) {
            int i = update[0];
            int j = update[1];
            int val = update[2];
            df->increment(i, j, val);
        }
        return df->result();



    }

};





