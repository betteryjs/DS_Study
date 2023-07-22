//
// Created by yjs on 2022/9/26.
//



#include <iostream>
#include <vector>
#include <random>


using namespace std;


class Solution {

public:


    void quickSort(vector<int> &arr, int low, int high) {
        if(low>=high) return;
       int q=randomPartition(arr,low,high);
        quickSort(arr, low, q);
        quickSort(arr, q+1, high);




    }
    int Partition(vector<int> &arr, int low, int high){
        int pivot = arr[low];
        int i = low - 1, j = high + 1;
        while (i < j) {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        return j;

    }

    int randomPartition(vector<int> &arr, int low, int high) {
        swap(arr[low], arr[low + rand() % (high - low+1)]);
        return Partition(arr, low, high);
    }


};


int main() {

    vector<int> res{2, 99,56, 23,12,89, 32, 88};
    Solution so;
    so.quickSort(res, 0, res.size() - 1);
    for (auto c: res) {
        cout << c << " ";

    }

    cout << endl;


    return 0;
}