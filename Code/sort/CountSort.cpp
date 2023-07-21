//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class CountSort {

    // only for 0~200 value
public:
    void countSort(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        int len = arr.size();
        vector<int>::value_type maxx = *max_element(arr.begin(), arr.end());
        vector<int>::value_type minx = *min_element(arr.begin(), arr.end());
        vector<int> tmp(maxx - minx + 1, 0);
        vector<int> ans;
        for (int i = 0; i < len; ++i) {
            tmp[arr[i] - minx]++;
        }
        for (int j = 0; j < maxx - minx + 1; ++j) {
            while (tmp[j] != 0) {

                ans.push_back(j + minx);
                tmp[j]--;
            }

        }
        copy(ans.begin(), ans.end(), arr.begin());

    }


};

int main() {

    return 0;
}