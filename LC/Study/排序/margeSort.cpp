//
// Created by yjs on 2022/4/25.
//

#include <bits/stdc++.h>


using namespace std;


class MargeSort {

public:

    void margeSort(vector<int> &nums, int left, int right) {

        //递归的终止情况
        if (left >= right) {
            return;
        }

        //第一步：分成子问题
        int mid = left + (right - left) / 2;


        //第二步：递归处理子问题
        margeSort(nums, left, mid);
        margeSort(nums, mid + 1, right);



        //第三步：合并子问题
        int k = 0;
        int i = left, j = mid + 1;

        vector<int> tmp(right - left + 1, 0);
        while (i <= mid && j <= right) {

            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];
        
        
         // 将tmp 复制到原数组中 

        for (k = 0, i = left; i <= right; k++, i++) nums[i] = tmp[k];


    }


};


class MargeSort2 {
private:

    vector<int> temp;

public:

    void sort(vector<int> &nums) {
        // 先给辅助数组开辟内存空间
        temp.resize(nums.size());
        // 排序整个数组（原地修改）
        margeSort(nums, 0, nums.size() - 1);
    }

    void margeSort(vector<int> &nums, int left, int right) {

        //递归的终止情况
        if (left == right) {
            // 单个元素不用排序
            return;
        }

        //第一步：分成子问题
        int mid = left + (right - left) / 2;


        //第二步：递归处理子问题
        margeSort(nums, left, mid);
        margeSort(nums, mid + 1, right);


        // 将两部分有序数组合并成一个有序数组
        merge(nums, left, mid, right);


    }

    void merge(vector<int> &nums, int lo, int mid, int hi) {
        // 先把 nums[lo..hi] 复制到辅助数组中
        // 以便合并后的结果能够直接存入 nums
        for (int i = lo; i <= hi; i++) {
            temp[i] = nums[i];
        }

        // 数组双指针技巧，合并两个有序数组
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (i == mid + 1) {
                // 左半边数组已全部被合并
                nums[p] = temp[j++];
            } else if (j == hi + 1) {
                // 右半边数组已全部被合并
                nums[p] = temp[i++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else if (temp[i] < temp[j]){
                nums[p] = temp[i++];
            }
        }
    }


};


int main() {


    MargeSort2 margesort;
    vector<int> nums{1, 25, 65, 99, 11, 12};

    margesort.sort(nums);

    for_each(nums.begin(), nums.end(), [](auto c) { cout << c << " "; });
    cout << endl;

    return 0;
}