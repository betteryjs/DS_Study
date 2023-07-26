//
// Created by yjs on 23-7-26.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> unorderedMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto  it=unorderedMap.find(target-nums[i]);
            if(it!=unorderedMap.end()){
                return {it->second,i};
            }else{
                unorderedMap[nums[i]]=i;
            }

        }
        return  {};
    }
};






int main(){

    Solution solution2;
    vector<int>nums{3,2,4};
    auto res=solution2.twoSum(nums,6);
    cout << res[0] << " "<< res[1]<< endl;


    return 0;
}