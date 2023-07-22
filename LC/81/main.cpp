#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int left=0,right=nums.size();

        while (left<right){

            int mid=left+(right-left)/2;
            if(target==nums[mid]){
                return true;
            }else if(nums[mid]<target){

                left=mid+1;
            }else if(nums[mid]>target){
                right=mid;
            }

        }
        return false;




    }
};
// @solution-sync:end

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    auto solution = Solution();
    auto result = solution.search(nums, target);
    cout << result << endl;

    return 0;
}
