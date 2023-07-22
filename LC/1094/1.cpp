//
// Created by yjs on 2022/4/18.
//

#include <bits/stdc++.h>


using namespace std;


class Difference {

private:
    vector<int> diff;


public:
    Difference(const vector<int> &nums) {
        diff.resize(nums.size());

        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void increment(const int &left, const int &right, int val) {

        diff[left] += val;
        if (right + 1 < diff.size()) {
            diff[right + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> ans(diff.size());
        ans[0] = diff[0];
        for (int i = 1; i < diff.size(); ++i) {

            ans[i] = ans[i - 1] + diff[i];

        }
        return ans;


    }


};



class Solution {
public:
    bool carPooling(vector <vector<int>> &trips, int capacity) {
        // 0 <= fromi < toi <= 1000 最多1001个车站
        vector<int> nums(1001,0);

        Difference *difference = new Difference(nums);

        for (const vector<int> &tripe: trips) {
            // val 乘客数量
            int val = tripe[0];
            // from 乘客上车时间
            int from = tripe[1];
            int to = tripe[2] - 1;
            difference->increment(from, to, val);

        }
        vector<int> res = difference->result();
        for (int i = 0; i < res.size(); ++i) {
            if (capacity < res[i]) {
                return false;
            }
        }
        return true;


    }
};


int main(){

    Solution go;
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};

    cout << go.carPooling(trips,4)<<endl;


    return 0;
}