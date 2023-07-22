#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &nums) {
        vector<int> cnt(1 << 16);
        for (const int &i: nums)
            for (const int &j: nums) {
                ++cnt[i & j];
            }
        int count = 0;
        for (int x: nums) {
            for (int i = 0; i < (1 << 16); ++i) {
                if ((x & i) == 0) {
                    count += cnt[i];
                }

            }

        }
        return count;


    }
};


