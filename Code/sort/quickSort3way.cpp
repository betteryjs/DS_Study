//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class QuickSort3way {
public:
public:

    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }

public:


    void quickSort1(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        quickSort1(arr, 0, arr.size() - 1);
    }

    void quickSort1(vector<int> &arr, int start, int end) {
        if (start >= end) return;
        int lt = start;
        int eq = start;
        int gt = end;
        int pivot = arr[eq];

        while (eq <= gt) {
            if (arr[eq] > pivot) swap(arr[eq], arr[gt--]);
            else if (arr[eq] < pivot) swap(arr[eq++], arr[lt++]);
            else eq++;
        }
        quickSort1(arr, start, lt - 1);
        quickSort1(arr, gt + 1, end);


    }

    void threeWayPartition(vector<int> &nums) {
        threeWayPartition(nums, 0, nums.size() - 1);
    }

    void threeWayPartition(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int lt = start;
        int eq = start;
        int gt = end;
        int base = nums[eq];
        while (eq <= gt) {
            if (nums[eq] > base) swap(nums[eq], nums[gt--]);
            else if (nums[eq] < base) swap(nums[lt++], nums[eq++]);
            else eq++;
        }
        threeWayPartition(nums, start, lt - 1);
        threeWayPartition(nums, gt + 1, end);
    }

    void comparator(vector<int> &arr) {
        sort(arr.begin(), arr.end());
    }

    vector<int> generateRandomArray(int maxSize, int maxValue) {

        uniform_real_distribution<> u(0, 1);
        uniform_int_distribution<unsigned> u2(0, maxValue + 1);
        default_random_engine e;
        vector<int> arr(maxSize * u(e));
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = u2(e);
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
            this->quickSort1(arr1);
            comparator(arr2);
            if (arr1 != arr2) {
                // 打印arr1
                // 打印arr2
                succeed = false;
                for (int j = 0; j < arr.size(); j++) {
                    cout << arr[j] << " ";
                }
                cout << endl;
                break;
            }
        }
        cout << (succeed ? "Nice!" : "Fucking fucked!") << endl;
        vector<int> arr = generateRandomArray(maxSize, maxValue);
        pprint("arr before ", arr);
        this->quickSort1(arr);
        pprint("arr after", arr);
    }


};


int main() {
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    QuickSort3way quickSort;


//    QuickSort::pprint("in", nums4);
//    // 2*O(n/2)+O(n)  ==> O(n*log(n))
//    quickSort.quickSort1(nums4);
//    QuickSort::pprint("out", nums4);
    quickSort.run();
//    quickSort
    return 0;
}