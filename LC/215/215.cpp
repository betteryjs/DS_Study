//
// Created by yjs on 2022/9/26.
//
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:

    int Partition(vector<int> &arr, int low, int high) {
        int pivot = arr[low];
        while (low < high) {

            while (low < high && arr[high] >= pivot) high--;
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot) low++;
            arr[high] = arr[low];


        }
        arr[low] = pivot;
        return low;

    }


    int randomPartition(vector<int> &arr, int low, int high) {
        swap(arr[low], arr[low + rand() % (high - low + 1)]);
        return Partition(arr, low, high);
    }

    int quickSelect(vector<int> &arr, int low, int hig, int target) {
        int p = randomPartition(arr, low, hig);
        if (p == target) {
            return target;
        } else {
            return p < target ? quickSelect(arr, p + 1, hig, target) :
                   quickSelect(arr, low, p - 1, target);

        }
    }


    int findKthLargest(vector<int> &nums) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() / 2);
    }
};

int main() {
    vector<int> nums{5, 2, 25, 65, 89, 55, 59, 32, 4, 1, 3, 20, 6, 11};
    int k = 4;


    Solution go;
    auto res = go.findKthLargest(nums, nums.size() / 2);
    cout << "res  " << res << endl;
    cout << "nums.size()/2 " << nums.size() / 2 << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}