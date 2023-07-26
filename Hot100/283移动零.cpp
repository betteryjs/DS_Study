#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j]) {
                swap(nums[i++], nums[j]);
            }
            j++;
        }


    }
};

int main() {
    Solution solution;
    solution.moveZeroes();
    return 0;
}