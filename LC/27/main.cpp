#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0){

            return 0;
        }
        int index=0;
        for (int i = 0; i < n; ++i) {
            if(nums[i]!=val){
                nums[index++]=nums[i];

            }
            
        }

        return index;




    }
};



class Solution2 {
public:
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

    Solution go;
    vector<int> nums={3,2,2,3};
    go.removeElement(nums,3);
    return 0;
}
