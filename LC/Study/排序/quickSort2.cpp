//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;












class QuickSort {
public:
 public:

     static void pprint(const string str, const vector<int> num) {
         cout << str << " [ ";
         for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
         cout << *(num.end() - 1) << " ]";
         cout << endl;
     }
     int quickSortParse(vector<int> & arr, int low, int hig) {
          vector<int>::value_type pivot =arr[low];
          while (low != hig) {
              while (low < hig && arr[hig] >= pivot  ) {
                  hig--;
              }
              arr[low]=arr[hig];
              while (low<hig && arr[low] <= pivot ) {
                  low++;
              }
              arr[hig]=arr[low];


          }
          arr[low] = pivot;
          return low;
    }



    // 快排递归版本
   void quickSort1(vector<int> &  arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        quickSort1(arr, 0, arr.size() - 1);
    }

     void quickSort1(vector<int> & arr, int L, int R) {
        if (L >= R) {
            return;
        }
        uniform_int_distribution<unsigned >u(L,R);
        default_random_engine e;
        swap(arr[u(e)], arr[L] );
        int piv  = quickSortParse(arr, L, R);
        quickSort1(arr, L, piv - 1);
        quickSort1(arr, piv + 1, R);
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
            this->quickSort1(arr1);
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
        this->quickSort1(arr);
        pprint("arr after",arr);
    }




};
class CheckSort{
private:
    function<void(vector<int>&)> functionSort;
public:
    CheckSort(const function<void(vector<int>&)> & function ) :functionSort(function){};
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    friend QuickSort;
public:

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
            this->functionSort(arr1);
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
        this->functionSort(arr);
        pprint("arr after",arr);
    }

};


int main() {
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    QuickSort quickSort;


//    QuickSort::pprint("in", nums4);
//    // 2*O(n/2)+O(n)  ==> O(n*log(n))
//    quickSort.quickSort1(nums4);
//    QuickSort::pprint("out", nums4);
    quickSort.run();
//    quickSort
    return 0;
}