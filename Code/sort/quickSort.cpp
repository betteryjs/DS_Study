//
// Created by yjs on 2022/4/25.
//


#include <bits/stdc++.h>


using namespace std;




class QuickSort {
public:


    void quickSort(int nums[], int left, int right) {

        if (left >= right) {
            return;
        }
        int  i = left - 1, j = right + 1;
        swap(nums[left],nums[left+rand()%(right-left)]);
        int x = nums[left];
        while (i < j) {
             while (nums[++i] < x); // 找到第一个大于等于x的元素
             while (nums[--j] > x); //  找到第一个小于等于x的元素
             if (i < j) swap(nums[i], nums[j]);
        }
        quickSort(nums,left,j);
        quickSort(nums,j+1,right);
    }


};


int main() {

    int n;
     const int N = 1000010;
    int nums[N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&nums[i]);
    }
    QuickSort quickSort;
    quickSort.quickSort(nums,0,n-1);
    for (int i = 0; i < n; i ++ ) printf("%d ", nums[i]);


    return 0;
}