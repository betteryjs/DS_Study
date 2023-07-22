//
// Created by yjs on 2022/9/26.
//
#include <bits/stdc++.h>


using namespace std;
class Solution {
public:

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

    int quickSelect(vector<int> & arr, int low , int hig , int target){

        int p = randomPartition(arr, low , hig);
        if(p==target){
            return arr[p];
        }else{
            return p < target ? quickSelect(arr, p+1,hig,target) :
            quickSelect(arr,low,p,target);

        }



    }


    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0, nums.size()-1, nums.size()-k);



    }
};

int main(){
    vector<int> nums{5,2,4,1,3,6,0};
    int k=4;


    Solution go;
    auto res=go.findKthLargest(nums,k);
    cout << res<<endl;



    return 0;
}