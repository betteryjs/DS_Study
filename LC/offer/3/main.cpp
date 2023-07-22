#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 1. unordered_map
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,bool> countMap;
        for (int i = 0; i < nums.size(); ++i) {
           if(countMap[nums[i]]){
               return nums[i];
           }
           countMap[nums[i]]= true;
        }
        return -1;
    }
};


class Solution2 {
public:
    // 1. sort
    int findRepeatNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());

        for (int i = 0; i <nums.size()-1 ; ++i) {
            if(nums[i]==nums[i+1]){
                return nums[i];
            }

        }
        return -1;

    }
};


class Solution3 {
public:
    // 1. unordered_set
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> countSet;
        for (int i = 0; i < nums.size(); ++i) {
            if(countSet.find(nums[i])!=countSet.end()){
                return nums[i];
            }
            countSet.emplace(nums[i]);


        }
        return -1;

    }
};



class Solution4 {
public:
    // 1. swap
    int findRepeatNumber(vector<int>& nums) {
        int index=0;
        while (index<nums.size()){
            if(nums[index]==index){

                index++;
                continue;

            }
            if(nums[nums[index]]==nums[index]){
                return nums[index];
            }

            swap(nums[index],nums[nums[index]]);

        }
        return -1;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
