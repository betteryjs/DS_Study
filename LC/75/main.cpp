#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// @solution-sync:begin
class Solution {
public:

    void sortColors(vector<int>& nums) {
        // 原地对它们进行排序
        int n=nums.size();
        int ptr=0;
        for (int i = 0; i < n; ++i) {
            if(nums[i]==0){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(nums[i]==1){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
























    }
};
// @solution-sync:end

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    auto solution = Solution();
    solution.sortColors(nums);

    return 0;
}
