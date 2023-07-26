//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ReversePair {
public:

    int reverPairNumber(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return 0;
        }
        return reverPairNumber(arr, 0, arr.size() - 1);
    }

    // arr[L..R]既要排好序，也要求逆序对数量返回
    // 所有merge时，产生的逆序对数量，累加，返回
    // 左 排序 merge并产生逆序对数量
    // 右 排序 merge并产生逆序对数量
    int reverPairNumber(vector<int> &arr, int l, int r) {
        if (l == r) {
            return 0;
        }
        // l < r
        int mid = l + ((r - l) >> 1);
        return reverPairNumber(arr, l, mid) + reverPairNumber(arr, mid + 1, r) + merge(arr, l, mid, r);
    }

    int merge(vector<int> &arr, int L, int m, int r) {
        vector<int> help(r - L + 1);
        int i = help.size() - 1;
        int p1 = m;
        int p2 = r;
        int res = 0;
        while (p1 >= L && p2 > m) {
            res += arr[p1] > arr[p2] ? (p2 - m) : 0;
            help[i--] = arr[p1] > arr[p2] ? arr[p1--] : arr[p2--];
        }
        while (p1 >= L) {
            help[i--] = arr[p1--];
        }
        while (p2 > m) {
            help[i--] = arr[p2--];
        }
        for (i = 0; i < help.size(); i++) {
            arr[L + i] = help[i];
        }
        return res;
    }


};

int main() {
    vector<int> arr{1,3,4,2,5};
    ReversePair reversePair;
    auto res=reversePair.reverPairNumber(arr);
    cout << res<<endl;

    return 0;
}