//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class BubbleSort {
public:
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    void bubbleSort(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        // 0 ~ N-1
        // 0 ~ N-2
        // 0 ~ N-3
        for (int e = arr.size() - 1; e > 0; e--) { // 0 ~ e
            for (int i = 0; i < e; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap_xor(arr,i,i + 1);
                }
            }
        }
    }

    static void swap_xor(vector<int> &  arr, int i, int j) {
        // i!=j
        // a==b ok *a==*b err !
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
};

int main() {
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    BubbleSort selectSort;
    BubbleSort::pprint("in", nums4);
    selectSort.bubbleSort(nums4);
    BubbleSort::pprint("out", nums4);
    return 0;
}