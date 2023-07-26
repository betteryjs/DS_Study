//
// Created by yjs on 2022/9/26.
//
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int> &arr, int lo, int hi, int target) {
        int mid = partation(arr, lo, hi);
        if (mid == target) return arr[mid];
        return mid < target ? quickSelect(arr, mid + 1, hi, target) : quickSelect(arr, lo, mid - 1, target);
    }

    int partation(vector<int> &arr, int lo, int hi) {
        swap(arr[lo], arr[lo + rand() % (hi - lo + 1)]);
        int pivot = arr[lo];
        while (lo < hi) {
            while (lo < hi && arr[hi] >= pivot) hi--;
            arr[lo] = arr[hi];
            while (lo < hi && arr[lo] <= pivot) lo++;
            arr[hi] = arr[lo];

        }
        arr[lo] = pivot;
        return lo;
    }
};


class Solution2 {
public:
    int findKthLargest(vector<int> &arr, int low, int high, int k) {
        bool flag = true;
        int low0 = 0, high0 = arr.size() - 1;
        while (flag) {
            swap(arr[low], arr[low + rand() % (high - low + 1)]);
            int pivot = arr[low];
            while (low < high) {
                while (low < high && arr[high] >= pivot) high--;
                arr[low] = arr[high];
                while (low < high && arr[low] <= pivot) low++;
                arr[high] = arr[low];
            }
            arr[low] = pivot;

            if (low == k) {
                flag = false;
                return low;
            } else if (low < k) {
                low0 = ++low;
                high = high0;

            } else {

                high0 = --high;
                low = low0;
            }
        }
        return 0;
    }


};


int main() {
    vector<int> nums{5, 2, 25, 65, 89, 55, 59, 32, 4, 1, 3, 20, 6, 11};


    Solution2 go;
    auto res = go.findKthLargest(nums, 0, nums.size() - 1, nums.size() / 2);
    cout << "res  " << res << endl;
    cout << "nums.size()/2 " << nums.size() / 2 << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}