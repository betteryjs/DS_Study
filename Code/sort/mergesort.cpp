//
// Created by yjs on 23-7-21.
//
//
// Created by yjs on 23-7-21.
//

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class  MergeSort{
private:
    vector<int> tmp;
    vector<int> arr;

public:

    MergeSort(vector<int> & arr) : arr(arr){
        tmp.resize(arr.size());
    }
    void merge(vector<int> & arr, int lo, int mid int ) {}


    void merge_sort(vector<int> &arr, int lo, int hig) {
        if (lo >= hig) return;
        int mid = lo + (hig - lo) / 2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid + 1, hig);
        merge(arr, lo, mid,hig);

    }




};



int main() {
    vector<int> arr{1, 56, 102, 89, 99, 26, 12, 45, 55};
    for_each(arr.begin(), arr.end(), [](auto c) { cout << c << " "; });
    cout << endl;
    merge_sort(arr, 0, arr.size() - 1);
    for_each(arr.begin(), arr.end(), [](auto c) { cout << c << " "; });


    return 0;
}





