//
// Created by yjs on 23-7-21.
//







#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class RadixSort {

public:
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }

    void raidx_sort(vector<int> &arr) {
        vector<int>::value_type max = *max_element(arr.begin(), arr.end());
        int numberOfDigits = 0;
        while (max > 0) {
            max /= 10;
            numberOfDigits++;
        }
        const int BUCKETS = 10;
        vector<vector<int>> buckets(BUCKETS);
        for (int poss = 0; poss <= numberOfDigits - 1; ++poss) {
            int denominator = static_cast<int> (pow(10, poss));
            for (int &tmp: arr) {
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
            this->raidx_sort(arr1);
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
        this->raidx_sort(arr);
        pprint("arr after", arr);
    }

};


int main() {


    RadixSort radixSort;
    radixSort.run();

    return 0;
}










