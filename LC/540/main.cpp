#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution2 {
public:
    int singleNonDuplicate(vector<int> &nums) {
        // binary search

        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mid-1>=0 && nums[mid] == nums[mid - 1] ) {
                if ((right - mid) % 2 == 0) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }

            }
            else if (mid+1 <nums.size() && nums[mid] == nums[mid + 1]) {

                if ((right + 1 - mid) % 2 == 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                return nums[mid];
            }


        }
        return nums[left];

    }


};

// @solution-sync:end

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        // binary search

        int left = 0, right = nums.size() ;
        int mid;
        while (left < right) {

            mid = left + (right - left) / 2;
           if(mid%2==0){

               if(mid+1<nums.size() && nums[mid]==nums[mid+1]){

                   left=mid+1;
               }else{
                   right=mid;
               }
           }else{
                if(mid>=0 && nums[mid]==nums[mid-1]){
                    left=mid+1;


                } else{
                    right=mid;
                }

           }


        }

        return nums[left];



    }


};

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    auto solution = Solution();
    auto result = solution.singleNonDuplicate(nums);
    cout << result << endl;

    return 0;
}
