//
// Created by yjs on 23-7-21.
//







#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class MergeSort {
private:
    vector<int> tmp;

public:
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    void  merge_sort(vector<int> &arr){
        tmp.resize(arr.size());
        merge_sort(arr,0,arr.size()-1);
    }

    void merge(vector<int> & arr, int lo, int mid ,int hig) {
        for (int i = lo; i <=hig; ++i) {
            tmp[i]=arr[i];
        }
        int i=lo,j=mid+1;
        for (int k = lo; k <=hig; ++k) {
            if(i==mid+1){
                arr[k]=tmp[j++];
            }else if(j==hig+1){
                arr[k]=tmp[i++];
            }else if(tmp[i]<tmp[j]){
                arr[k]=tmp[i++];
            }else{
                arr[k]=tmp[j++];

            }

        }

    }


    void merge_sort(vector<int> &arr, int lo, int hig) {
        if (lo >= hig) return;
        int mid = lo + (hig - lo) / 2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid + 1, hig);
        merge(arr, lo, mid,hig);

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
            this->merge_sort(arr1);
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
        this->merge_sort(arr);
        pprint("arr after",arr);
    }

};


int main() {


    MergeSort mergeSort;
    mergeSort.run();
    return 0;
}










