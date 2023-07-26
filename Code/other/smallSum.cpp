//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class SmallSum {

public:
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    int smallSum(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return 0;
        }
        return smallSum(arr, 0, arr.size() - 1);
    }

    // arr[L..R]既要排好序，也要求小和返回
    // 所有merge时，产生的小和，累加
    // 左 排序   merge
    // 右 排序  merge
    // merge
    int smallSum(vector<int> &arr, int l, int r) {
        if (l == r) {
            return 0;
        }
        // l < r
        int mid = l + ((r - l) >> 1);
        return
                smallSum(arr, l, mid)
                +
                smallSum(arr, mid + 1, r)
                +
                merge(arr, l, mid, r);
    }

    int merge(vector<int> &arr, int L, int m, int r) {
        vector<int> help(r - L + 1);
        int i = 0;
        int p1 = L;
        int p2 = m + 1;
        int res = 0;
        while (p1 <= m && p2 <= r) {
            res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
            help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        }
        while (p1 <= m) {
            help[i++] = arr[p1++];
        }
        while (p2 <= r) {
            help[i++] = arr[p2++];
        }
        for (i = 0; i < help.size(); i++) {
            arr[L + i] = help[i];
        }
        return res;
    }

};

int main() {
    vector<int> arr{1,3,4,2,5};
    SmallSum smallSum;
    auto res=smallSum.smallSum(arr);
    cout << res<<endl;




    return 0;
}