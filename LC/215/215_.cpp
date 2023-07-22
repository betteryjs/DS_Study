//
// Created by yjs on 2022/9/26.
//
#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {



    }


    void  maxHeapify(vector<int> & arr, int heapSize){




    }


    void BuildHeap(vector<int> & arr,int heapSize){

        for (int i = heapSize/2; i >=0 ; --i) {
            maxHeapify(arr, i, heapSize);
        }

    }
};