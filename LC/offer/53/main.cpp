#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    // 1. O(n)
    int search(vector<int> &nums, int target) {
        int count = 0;
        for (const int &num: nums) {
            if (num == target) {
                count++;
            }
        }
        return count;
    }
};


class Solution2 {
public:
    // 1. O(nlog(n))
    int search(vector<int> &nums, int target) {
        vector<int>::iterator iterator = std::lower_bound(nums.begin(), nums.end(), target);
        if (iterator == nums.end()) {
            return 0;
        }
        vector<int>::iterator iterator2 = std::upper_bound(nums.begin(), nums.end(), target);

        int count = 0;
        while (iterator != iterator2) {
            count++;
            iterator++;

        }
        return count;


    }

};


class Solution3 {
public:
    // 1. O(n)
    int search(vector<int> &nums, int target) {
        int pos = this->lowerBound(nums, target);
        if (pos == -1) {
            return 0;
        } else {
            return this->upperBound(nums, target) - pos + 1;

        }
    }

    int lowerBound(const vector<int> &arr, int target) {
        int low = 0;
        int high = arr.size();
        int isFind = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                high = mid;
                isFind++;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else if (arr[mid] > target) {
                high = mid;
            }
        }
        if (isFind) {
            return low;
        } else {
            return -1;
        }


    }

    int upperBound(const vector<int> &arr, int target) {
        int low = 0;
        int high = arr.size();
        int isFind = 0;


        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                low = mid + 1;
                isFind++;

            } else if (arr[mid] < target) {
                low = mid + 1;
            } else if (arr[mid] > target) {
                high = mid;
            }
        }
        if (isFind) {
            return low - 1;
        } else {
            return -1;
        }
    }
};


class Solution4 {
public:
    // 1. O(n)
    int search(vector<int> &nums, int target) {
        return helper(nums,target)-helper(nums,target-1);


    }

    int helper(const vector<int> &nums, const int &tar) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (nums[m] <= tar) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return i;
    }


};


int main() {

    Solution3 go;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    auto res = go.lowerBound(nums, 8);
    auto res2 = go.upperBound(nums, 7);
    std::cout << res << std::endl;
    std::cout << res2 << std::endl;
    return 0;
}
