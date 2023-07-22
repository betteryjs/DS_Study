//
// Created by yjs on 2022/4/16.
//

#include <bits/stdc++.h>

using namespace std;



// time O(n logn)
class Solution {
public:
    int findClosestNumber(vector<int> &nums) {
        // 1. sort
        sort(nums.begin(), nums.end());
        for (const int & c:nums) {
            cout << c<< " ";
        }
        cout <<endl;


        // binary search 0
        // find the last 0
        int pos1 = -1, pos2 = -1; // pos1 is -1 pos2 is 1
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                pos1 = mid;
                left = mid+1;

            } else if (nums[mid] == 0) {

                return 0;
            } else {
                // nums[mid]>0
                pos2 = mid;
                right = mid-1;

            }
        }
        cout << pos1 <<endl;
        cout << pos2 <<endl;

        if(pos1==-1  ){
            // all is -1
            return nums[0];

        }
        if(pos2==-1){

            return nums[nums.size()-1];

        }

        if(nums[pos2]>(-nums[pos1])){
            return nums[pos1];
        }else{

            return nums[pos2];
        }

    }
};

// time O(n)
class Solution2 {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int x : nums) {
            if (abs(x) < abs(ans)) ans = x;
            else if (abs(x) == abs(ans)) ans = max(ans, x);
        }
        return ans;
    }
};



int main(){

    Solution go;
    vector<int> nums{-10,-12,-54,-12,-544,-10000};
    auto  res=go.findClosestNumber(nums);



}