#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;




// unordered_map
class Solution {
public:
    int majorityElement(vector<int>& nums) {


        unordered_map<int,int> countMap;

        for (const int & num:nums) {
            ++countMap[num];
        }

        for(auto [num,count]:countMap){

            if(count*2>nums.size()){

                return num;
            }

        }
        return -1;






    }
};


// 摩尔投票法
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int x=0,votes=0,count;
        for (const int & num:nums) {
            if(votes==0){

                x=num;

            }
            votes+=num==x?1:-1;
        }
        // x is max;
        for(int num : nums){
            if(num == x){

                count++;

            }


        }

        return count > nums.size() / 2 ? x : 0; // 当无众数时返回 0



    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
