#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// 枚举 o(n^2)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <nums.size() ; ++j) {
                    if(i<j && abs(nums[i]-nums[j])==k){
                        count++;
                    }


            }
        }

        return count;

    }
};


class Solution2 {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
       unordered_map<int,int>map;
        for (int j = 0; j < n; ++j) {
            res+=(map.count(nums[j]-k) ? map[nums[j]-k] :0);
            res+=(map.count(nums[j]+k) ? map[nums[j]+k] :0);
            // 值 ： 值的个数
            map[nums[j]]++;
        }
        return res;
    }
};




int main() {


    Solution2 go;
    vector<int> nums{1,2,2,1};
    int k=1;
    go.countKDifference(nums,k);
    return 0;
}
