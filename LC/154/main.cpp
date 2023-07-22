#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = nums.size() - 1;
        int mid, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 如果左面有序
            if (nums[mid] < nums[right]) {
                // binary search
                right = mid ;


            } else if (nums[mid] > nums[right]) {

                left = mid + 1;
            } else if (nums[mid] == nums[right]) {

                right--;
            }


        }


        return nums[left];


    }
};
// @solution-sync:end

int main() {
    vector<int> nums = {3, 1, 3};

    auto solution = Solution();
    auto result = solution.findMin(nums);
    cout << result << endl;

    return 0;
}
