#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += max(nums[i - 1], 0); // if nums[i - 1]<0 add 0 else add nums[i - 1]
            res = max(res, nums[i]);
        }
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
