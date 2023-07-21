//
// Created by yjs on 23-7-21.


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
        if (arr.empty() || arr.size() < 2) return;
        bool flag = false;
        for (int e = arr.size() - 1; e >= 0; --e) {
            for (int i = 0; i < e; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    flag = true;
                }
            }
            if (!flag) break;
        }
    }


    // i和j是一个位置的话，会出错
    static void swap_xor(vector<int> &arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }


    void comparator(vector<int> &arr) {
        sort(arr.begin(), arr.end());
    }

    vector<int> generateRandomArray(int maxSize, int maxValue) {

        uniform_real_distribution<> u(0,1);
        uniform_int_distribution<unsigned > u2(0,maxValue + 1);
        default_random_engine e;
        vector<int> arr(maxSize*u(e));
        for (int i = 0; i < arr.size(); i++) {
            arr[i]=u2(e);
        }
        return arr;


    }


    void run() {
        int testTime = 500000;
        int maxSize = 100; // 随机数组的长度0～100
        int maxValue = 100;// 值：-100～100
        bool succeed = true;
        for (int i = 0; i < testTime; i++) {
            vector<int> arr = generateRandomArray(maxSize, maxValue);

            vector<int> arr1(arr);
            vector<int> arr2(arr);
            this->bubbleSort(arr1);
            comparator(arr2);
            if (arr1!=arr2) {
                // 打印arr1
                // 打印arr2
                succeed = false;
                for (int j = 0; j < arr.size(); j++) {
                    cout << arr[j] <<  " ";
                }
                cout << endl;
                break;
            }
        }
        cout << (succeed? "Nice!" : "Fucking fucked!")<<endl;
        vector<int> arr = generateRandomArray(maxSize, maxValue);
        pprint("arr before ",arr);
        this->bubbleSort(arr);
        pprint("arr after",arr);
    }


};


int main() {
//    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};
//
//    InsertSort selectSort;
//    InsertSort::pprint("in", nums4);
//    selectSort.insertSort(nums4);
//    InsertSort::pprint("out", nums4);

    BubbleSort bubbleSort;
    bubbleSort.run();
    return 0;
}






