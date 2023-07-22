#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<int> nums;

    Solution(vector<int> &_nums) {
        nums = _nums;
        n = _nums.size();

    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < n; ++i) {
            swap(nums, i, i + (rand() % (n - i)));
        }
        return nums;
    }


    void swap(vector<int> &nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
