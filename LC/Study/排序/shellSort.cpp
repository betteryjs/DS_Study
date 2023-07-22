//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ShellSort{


public:


    void shellSort1(vector<int> &nums) {
        int len = nums.size();
// 分类间隔
        for (int k = len / 2; k > 0; k /= 2) {
// 对每个子数组 进行 插入排序，
// 第一个未排序元素为 k ,前k个元素 为有序的 k 个子序列
            for (int i = k; i < len; i++) {
                int tmp = nums[i];
                int j = i - k;
                for (; j >= 0; j -= k) {
                    if (nums[j] > tmp) nums[j + k] = nums[j];
                    else break;
                }
                nums[j + k] = tmp;
            }
        }
    }

// 交换法
    void shellSort2(vector<int> &nums) {
        int len = nums.size();
        for (int gap = len / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < len; i++) {
                for (int j = i - gap; j >= 0; j -= gap) {
                    if (nums[j] > nums[j + gap]) {
                        swap(nums[j + gap], nums[j]);
                    } else break;
                }
            }
        }
    }

};

int main() {

    return 0;
}