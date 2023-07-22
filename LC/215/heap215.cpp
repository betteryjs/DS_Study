#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l <= heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r <= heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    void heap_sort(vector<int>& arr) {
        int len = arr.size()-1;
        buildMaxHeap(arr, len);
        for (int i = len ; i >=1; i--) {
            swap(arr[i], arr[0]);
            len--;
            maxHeapify(arr, 0, len);
        }
    }




};
// @solution-sync:end







int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4, 16 , 15 };

    auto solution = Solution();
    solution.heap_sort(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}
