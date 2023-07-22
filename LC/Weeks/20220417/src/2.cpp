//
// Created by yjs on 2022/4/17.
//
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int minimumRounds(vector<int>& tasks) {


        // sort
        unordered_map<int  ,int> countMap;
        for (const int & task : tasks) {
            ++countMap[task];

        }
        int count=0;
        for (auto  [key,value] : countMap) {
            if (value == 1) return -1;
            else if (value == 2) count++;
            else if (value % 3 == 0) count += value / 3;
            else count += (value / 3) -1 + 2;
        }
        return count;









    }
};


int main(){

    Solution go;

    vector<int> nums{7,7,7,7,7,7,7};
    go.minimumRounds(nums);

    return 0;
}

