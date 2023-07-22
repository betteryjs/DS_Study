//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class MergeSort {

public:
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    void merge(vector<int> & arr, int L, int M, int R) {
        vector<int> help = vector<int>(R - L + 1);
        int i = 0;
        int start1 = L ,end1=M;
        int start2 = M + 1,end2=R;
        while (start1 <= end1 && start2 <= end2) {
            help[i++] = arr[start1] <= arr[start2] ? arr[start1++] : arr[start2++];
        }
        // 要么p1越界了，要么p2越界了
        while (start1 <= end1) {
            help[i++] = arr[start1++];
        }
        while (start2 <= end2) {
            help[i++] = arr[start2++];
        }
        // copy help to arr
//        for (i = 0; i < help.size(); i++) {
//            arr[L + i] = help[i];
//        }
        copy(help.begin(),help.end(),arr.begin()+L);
    }

    void mergeSortIteration(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        int N = arr.size();
        // 步长
        int mergeSize = 1;
        while (mergeSize < N) { // log N
            // 当前左组的，第一个位置
            int L = 0;
            while (L < N) {
                if (mergeSize >= N - L) {
                    break;
                }
                int M = L + mergeSize - 1;
                int R = M + min(mergeSize, N - M - 1);
                merge(arr, L, M, R);
                L = R + 1;
            }
            // 防止溢出
            if (mergeSize > N / 2) {
                break;
            }
            mergeSize <<= 1;
        }
    }

    void mergeSortRecursion(vector<int> &arr){
        this->mergeSortRecursion(arr,0,arr.size()-1);
    }
    void mergeSortRecursion(vector<int> &arr, int L, int R) {
        if (L == R) { // base case [L,R]
            return;
        }
        int mid = L + ((R - L) >> 1);
        mergeSortRecursion(arr, L, mid);
        mergeSortRecursion(arr, mid + 1, R);
        // 合并
        merge(arr, L, mid, R);
    }

};;

int main() {
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    MergeSort mergeSort;
    MergeSort::pprint("in", nums4);
    // 2*O(n/2)+O(n)  ==> O(n*log(n))
    mergeSort.mergeSortRecursion(nums4);
    MergeSort::pprint("out", nums4);


    vector<int> nums5{2, 3, 56, 25, 26, 999, 19, 16, 23};

    MergeSort mergeSort2;
    MergeSort::pprint("in", nums5);
    mergeSort.mergeSortIteration(nums5);
    MergeSort::pprint("out", nums5);



    return 0;
}