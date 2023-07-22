#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int i = 0, j = nums.size() - 1;

        while (i < j)
        {
            while(i < j && (nums[i] & 1) == 1) i++;
            while(i < j && (nums[j] & 1) == 0) j--;
            swap(nums[i], nums[j]);
        }
        return nums;














    }
};
// @solution-sync:end

#include <sstream>

string toString(vector<int> v) {
    stringstream out;
    out << "[";
    unsigned long size = v.size();
    for (int i = 0; i < size; ++i) {
        out << v[i];
        if (i < size - 1)
            out << ",";
    }
    out << "]";
    return out.str();
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    auto solution = Solution();
    auto result = solution.exchange(nums);
    cout << toString(result) << endl;

    return 0;
}