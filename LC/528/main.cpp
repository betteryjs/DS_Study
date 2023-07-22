#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Solution {
private:
    vector<int> preSum;

public:
    Solution(vector<int> &w) {
        int n = w.size();
        preSum.resize(n + 1);

        preSum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + w[i - 1];

        }


    }

    int pickIndex() {

        int n = preSum.size();
//        mt19937 gen;
//
//        uniform_int_distribution<int> dis(1,preSum[n-1]);
//        default_random_engine  e;
        // target 取值范围是闭区间 [1, preSum[n - 1]]



//        int target=dis(gen);
//        int target = (rand() % (preSum[n - 1] - 1 + 1)) + 1;

        std::uniform_int_distribution<int> dist{1, preSum[n - 1]};
        std::random_device rd; // Non-deterministic seed source
        std::default_random_engine randomEngine{rd()}; // Create random number generator
        int target = dist(randomEngine);

//        return lower_bound(preSum.begin(),preSum.end(), target) - preSum.begin()-1;
        return left_bound(preSum, target) - 1;
    }


    int left_bound(vector<int> nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size(); // 注意

        while (left < right) { // 注意
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid; // 注意
            }
        }
        return left;
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
    int main() {
        return 0;
    }
