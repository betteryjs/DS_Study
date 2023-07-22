//
// Created by yjs on 2022/6/3.
//

#include <bits/stdc++.h>


using namespace std;


class TestMinMax {

public:

    // 1 2n-1
    pair<int, int> getMinMax(const vector<int> &nums) {
        int count = 0;
        int min = nums[0];
        int max = nums[0];

        for (int i = 1; i < nums.size(); ++i) {

            max = max >= nums[i] ? max : nums[i];
            count++;
            min = min <= nums[i] ? min : nums[i];
            count++;


        }
        cout << "first count is  [ 2(n-1) ] : " << count << endl;
        return {min, max};


    }


    pair<int, int> getMinMax2(const vector<int> &nums) {

        if ((int) nums.size() == 0) {
            return {};
        }
        int count = 0;

        int min = nums[0];
        int max = nums[0];
        if ((int) nums.size() == 1) {
            return {nums[0], nums[0]};
        }


        // 数组长度是偶数   首先对第一对元素进行比较
        if ((int) nums.size() % 2 == 0) {


            if (nums[0] < nums[1]) {
                max = nums[1];
                min = nums[0];

            } else {
                max = nums[0];
                min = nums[1];

            }
            count++;

            for (int i = 2; i < nums.size() - 1; i += 2) {
                if (nums[i] > nums[i + 1]) {
                    max = std::max(max, nums[i]);
                    min = std::min(min, nums[i + 1]);
                    count += 2;


                } else {
                    max = std::max(max, nums[i + 1]);
                    min = std::min(min, nums[i]);
                    count += 2;
                }
                count++;


            }
            cout << "偶数 count is : [ 3 * n/2 -2 ] " << count << endl;

        } else {
            // 如果数组的长度为奇数 将min max 设置成第一个数 再成对的进行比较
            max = nums[0];
            min = nums[0];
            for (int i = 1; i < nums.size() - 1; i += 2) {

                if (nums[i] > nums[i + 1]) {
                    max = std::max(max, nums[i]);
                    min = std::min(min, nums[i + 1]);
                    count += 2;

                } else {
                    max = std::max(max, nums[i + 1]);
                    min = std::min(min, nums[i]);
                    count += 2;

                }
                count++;
            }
            cout << "奇数 count is  [ 3* ( (n-1) /2 ) ] : " << count << endl;


        }


        return {min, max};
    }


};


int main() {
    TestMinMax *testMinMax = new TestMinMax;

    vector<int> nums{1, 26, 23, 56, 25};
    auto res = testMinMax->getMinMax(nums);
    cout << " min : " << res.first << " max :  " << res.second << endl;
    res = testMinMax->getMinMax2(nums);
    cout << " min : " << res.first << " max :  " << res.second << endl;


    return 0;
}
