#include <iostream>
#include <bits/stdc++.h>


using namespace std;


// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target) {

                return vector<int>{left + 1, right + 1};

            } else if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            }

        }
        return vector<int>{-1, -1};


    }
};


// 二分查找
class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {


        for (int i = 0; i < numbers.size(); ++i) {

            int left = i;
            int right = numbers.size() - 1;
            while (left <= right) {
                int mid = left + (left + right) / 2;
                if (numbers[mid] == target - numbers[i]) {
                    return vector<int>{i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return vector<int>{-1, -1};


    }
};


int main() {


    Solution2 go;
    vector<int> num{2, 7, 11, 15};
    int tag = 9;

    auto ans = go.twoSum(num, tag);
    for (auto c: ans) {
        cout << c << endl;
    }

    return 0;
}
