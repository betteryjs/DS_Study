#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// @solution-sync:begin
class Solution {
public:





    void maxHeapify(vector<int> &arr, int i, int heapSize) {
        while (2*i+1<=heapSize){
            int leftChild=(2*i)+1,rightChild=(2*i)+2,target=leftChild;
            if(rightChild <=heapSize && arr[rightChild]> arr[leftChild]){
                target=rightChild;
            }
            if(arr[target] > arr[i]){
                swap(arr[target],arr[i]);
            }else{
                break;
            }
            i=target;
        }
    }

    void maxHeapify2(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l <= heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r <= heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify2(a, largest, heapSize);
        }
    }





    void build_heap(vector<int> &arr, int size) {
        for (int i =  size/2; i >= 0; i--) {
            maxHeapify(arr, i, size);
        }
    }

    void heap_sort(vector<int> & arr) {
        int len=arr.size()-1;
        build_heap(arr, len);
        for (int i = len ; i >=1; i--) {
            swap(arr[i], arr[0]);
            len--;
            maxHeapify(arr, 0, len);
        }
    }


};
// @solution-sync:end


class Solution2 {
public:
    void minHeapify(vector<int> &arr, int i, int heapSize) {
        while (2*i+1<=heapSize){
            int leftChild=(2*i)+1,rightChild=(2*i)+2,target=leftChild;
            if(rightChild <=heapSize && arr[rightChild]> arr[leftChild]){
                target=rightChild;
            }
            if(arr[target] > arr[i]){
                swap(arr[target],arr[i]);
            }else{
                break;
            }
            i=target;
        }
    }


    void build_heap(vector<int> &arr, int size) {
        for (int i =  size/2; i >= 0; i--) {
            minHeapify(arr, i, size);
        }
    }

    void heap_sort(vector<int> & arr) {
        int len=arr.size()-1;
        build_heap(arr, len);
        for (int i = len ; i >=1; i--) {
            swap(arr[i], arr[0]);
            len--;
            minHeapify(arr, 0, len);
        }
    }


};








int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4, 16 , 15 };

    auto solution = Solution();
    solution.heap_sort(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }



    return 0;
}
