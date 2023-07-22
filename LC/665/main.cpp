#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        if (nums.size() < 3) {
            return true;
        }
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {

            if (nums[i - 1] > nums[i]) {
                if (i == 1) {

                    nums[i - 1] = nums[i];

                } else if (nums[i] >= nums[i - 2]) {

                    nums[i - 1] = nums[i];

                } else {
                    nums[i] = nums[i - 1];
                }
                count++;
            }
            if(count>1){
                return false;
            }
        }
        return true;

    }
};

int main() {
    Solution go;
    vector<int> nums{1,4,1,2};
    auto res=go.checkPossibility(nums);
    cout << res<<endl;

    return 0;
}
