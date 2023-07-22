#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// @solution-sync:begin


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // select sort k
        priority_queue<int,vector<int>,less<int>> priorityQueue;
        for (int & num:nums) {
            priorityQueue.push(num);
        }
        int index=0;
        while (!priorityQueue.empty()){
            index++;
            if(index==k){
                return priorityQueue.top();
            }
            priorityQueue.pop();
        }
    }
};





int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    auto solution = Solution();
    auto result = solution.findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}
