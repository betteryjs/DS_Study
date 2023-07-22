#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};

        int lower = this->lower_bound(nums, target);
        int upper = this->upper_bound(nums, target) ; // 这里需要减1位
        if (lower == nums.size() || nums[lower] != target) {
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper};


    }



    int lower_bound(const vector<int> & nums,const int & target){
        int left=0,right=nums.size()-1,mid;
        while (left<=right){
                mid=left+(right-left)/2;
                if(nums[mid]==target){

                    right=mid-1;
                } else if(nums[mid]<target){
                    left=mid+1;
                }else if(nums[mid]>target){
                    right=mid-1;
                }
        }
        return left;
    }
    int upper_bound(const vector<int> & nums,const int & target){

        int left=0,right=nums.size(),mid;
        while (left<right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                left=mid+1;
            }else if(nums[mid]>target){

                right=mid;
            } else if(nums[mid]<target){
                left=mid+1;
            }

        }
        return right-1;


    }




};
// @solution-sync:end

#include <sstream>

string toString(vector<int> v) {
    stringstream out;
    out << "[";
    unsigned long size = v.size();
    for (int i = 0; i < size; ++i) {
        out << v[i];
        if (i < size - 1)
            out << ",";
    }
    out << "]";
    return out.str();
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    auto solution = Solution();
    auto result = solution.searchRange(nums, target);
    cout << toString(result) << endl;

    return 0;
}
