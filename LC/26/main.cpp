#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// 快慢指针
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {

            return 0;
        }

        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];


            }
            fast++;


        }
        return slow + 1;


    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }

       int index=0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[index]!=nums[i]){

                nums[++index]=nums[i];


            }


        }
        return index+1;

    }
};


int main() {
    return 0;
}
