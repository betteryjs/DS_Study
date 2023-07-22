#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.empty()){
           return -1;
        }
        if(nums.size()==1){
            return nums[0]==target ? 0:-1;
        }
        int left=0,right=nums.size()-1;
        int mid;
        while (left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[0]<=nums[mid]){
                // left 有序
                if(nums[0]<=target && target< nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else if(nums[0]>nums[mid]){
                // right 有序
                if(target>=nums[mid] && target<= nums[nums.size()-1]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }


            }




        }
        return -1;







    }
};
// @solution-sync:end

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    auto solution = Solution();
    auto result = solution.search(nums, target);
    cout << result << endl;

    return 0;
}
