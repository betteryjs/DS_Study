#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p= removeElement(nums,0);
        for (; p <nums.size() ; ++p) {
                nums[p]=0;
        }
    }

    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0){

            return 0;
        }
        int slow=0,fast=0;
        while (fast<n){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];


            }
            fast++;


        }
        return slow;
    }
};




int main() {


    return 0;
}
