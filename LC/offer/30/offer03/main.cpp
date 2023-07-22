#include <iostream>

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {

public:
    // time O(n) space O(n)

    int findRepeatNumber(vector<int> &nums) {
        unordered_map<int, bool> map;
        for (int num: nums) {
            if (map[num]) {
                return num;
            }
            map[num] = true;
        }
        return -1;
    }
};


class Solution2 {

public:
    // time O(n) space O(n)

    int findRepeatNumber(vector<int> &nums) {
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] == index) {
                index++;
                continue;
            }
            if (nums[index] == nums[nums[index]]) {
                return nums[index];
            }
            swap(nums[index], nums[nums[index]]);
        }
        return -1;
    }
};


class Solution3 {

public:
    // time O(n) space O(n)
    int findRepeatNumber(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        for (int index = 1; index < nums.size(); ++index) {
            if(nums[index]==nums[index-1]){
                return nums[index];
            }
        }
        return -1;
    }
};

int main() {

    Solution3 go;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int res = go.findRepeatNumber(nums);
    cout << res << endl;




    return 0;
}
