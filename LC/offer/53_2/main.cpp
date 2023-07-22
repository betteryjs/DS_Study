#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;





class Solution {
public:
    // O(n)
    int missingNumber(vector<int>& nums) {

       int len=nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]!=i){
                return i;
            }
        }
        return len;


    }
};



class Solution2 {
public:
    // O(n)
    int missingNumber(vector<int>& nums) {
        int low=0,hight=nums.size()-1;
        while (low<=hight){
            int mid=low+(hight-low)/2;
            if(nums[mid]==mid){
                low=mid+1;
            }else{
             hight=mid-1;
            }

        }
        return low;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
