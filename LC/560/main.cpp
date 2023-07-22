#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> perSum;
public:
    int subarraySum(vector<int>& nums, int k) {
        perSum.resize(nums.size()+1);
        // perSum[0]=0
        perSum[0]=0;
        for (int i = 0; i <nums.size(); ++i) {
            perSum[i+1]=perSum[i]+nums[i];

        }

        int res = 0;
        // 穷举所有子数组
        for (int i = 1; i <=nums.size(); ++i) {
            for (int j = 0; j <i; ++j) {
                if(perSum[i]-perSum[j]==k){
                    res++;
                }

            }

        }
        return res;



    }
};

// unordered_map

class Solution2 {
private:

    vector<int> perSum;

public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> countMap; // 前缀和为k的数有n个
        countMap[0]=1;
        int count=0,sum0_i=0;
        for (int i = 0; i < nums.size(); ++i) {
            // sum0_i 前缀和 nums [0,i]
            sum0_i+=nums[i];
            int sumNeed=sum0_i-k;
            if(countMap.find(sumNeed) !=countMap.end()){
                count+=countMap[sumNeed];
            }
            countMap[sum0_i]++;


        }
        return count;







    }
};



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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
