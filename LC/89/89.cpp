//
// Created by yjs on 23-2-23.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        int head = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(head + res[j]);

            }
            head = head << 1;
        }
        return res;


    }
};


//* int gray(x) {
//    return x ^ (x >> 1);
//}*/
// /
// /
// [0,..2^n−1]
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> res{};
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back(gray(i));
            
        }
        return res;


    }

    int gray(int x) {
        return x ^ (x >> 1);
    }
};


