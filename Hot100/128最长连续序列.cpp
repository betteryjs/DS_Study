#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numsSet;

        for (const int &num: nums) {
            numsSet.insert(num);
        }
        int longestStreak = 0;

        for (const int &num: nums) {

            if (!numsSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (numsSet.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;

                }
                longestStreak=max(longestStreak,currentStreak);


            }

        }


        return longestStreak;



    }
};



int main() {
    return 0;
}