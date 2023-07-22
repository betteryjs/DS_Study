#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        for (int i = 0, j = nums.size() - 1; i < j; ++i) {

            if (nums[i] % 2 == 1) {

                int c = nums[j];
                nums[j--] = nums[i];
                nums[i--] = c;


            }
        }
        return nums;


    }
};

int main() {

    Solution go;
    vector<int> nums{3, 1};
    auto res = go.sortArrayByParity(nums);
    for_each(res.begin(), res.end(), [](auto c) { cout << c << " "; });


    return 0;
}
