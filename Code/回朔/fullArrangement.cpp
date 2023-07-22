//
// Created by yjs on 2022/4/23.
//

#include <bits/stdc++.h>

using namespace std;

class fullArrangement {

private:
    vector<int> nums;
    vector<vector<int>> Result;

public:
    fullArrangement(const vector<int> &nums) : nums(nums) {


    }

    vector<vector<int>> perMute() {
        vector<int> res;
        backTrack(res);
        return Result;

    }

    void backTrack(vector<int> &res) {

        if (res.size() == nums.size()) {
            Result.push_back(res);
        }
        for (int i = 0; i < nums.size(); ++i) {

            if (find(res.begin(), res.end(), nums[i]) != res.end()) {

                continue;


            }

            res.push_back(nums[i]);

            backTrack(res);
            res.pop_back();


        }


    }


};


int main() {

    vector<int> nums{1, 2, 3};
    fullArrangement *fullarrangement = new fullArrangement(nums);
    auto res = fullarrangement->perMute();
    for (auto c: res) {

        cout << " [ ";
        for_each(c.begin(), c.end(), [](const int &b) { cout << b << " "; });

        cout << " ] " << endl;
    }
    cout << endl;
    return 0;


}