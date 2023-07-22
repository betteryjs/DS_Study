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
        quickSort(arr, low, q-1);
        quickSort(arr, q+1, high);




    }
    int Partition(vector<int> &arr, int low, int high){
        int pivot = arr[low];
        while (low < high) {

            while (low < high && arr[high] >= pivot) high--;
            arr[low]=arr[high];
            while (low < high && arr[low] <= pivot) low++;
            arr[high]=arr[low];
        }
        arr[low]=pivot;
        return low;

    }

    int randomPartition(vector<int> &arr, int low, int high) {
        swap(arr[low], arr[low + rand() % (high - low)]);
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