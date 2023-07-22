//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class RadixSort{


public:

    void radixSort(vector<int> &arr) {
        // get numberOfDigits  : numberOfDigits为位数
        vector<int>::value_type max = *max_element(arr.begin(), arr.end());
        int numberOfDigits = 0;
        while (max > 0) {
            max /= 10;
            numberOfDigits++;
        }
        const int BUCKETS = 10; // 0-9 10 个数字
        vector<vector<int>> buckets(BUCKETS);
        for (int poss = 0; poss <= numberOfDigits - 1; ++poss) {
            int denominator = static_cast<int> (pow(10, poss));
            for (int &tmp: arr) {
                // (tmp / denominator) % 10 得到最低位的值
                buckets[(tmp / denominator) % 10].push_back(tmp);

            }
            int index = 0;
            for (auto &thebuckett: buckets) {
                for (int &k: thebuckett) {
                    arr[index++] = k;

                }
                                    thebuckett.clear();
            }
        }
    }

};

int main() {

    return 0;
}