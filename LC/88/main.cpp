#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// 双指针 time O(m+n) kong O(m+n)
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> ans;
        int left1 = 0, left2 = 0;
        while (left1 < m || left2 < n) {
            if(left1==m){
               ans.push_back(nums2[left2++]);
            }else if(left2==n){
                ans.push_back(nums1[left1++]);
            }else if (nums1[left1] < nums2[left2]) {
                ans.push_back(nums1[left1++]);
            }else{
                ans.push_back(nums2[left2++]);
            }
        }
        for (int i = 0; i < m+n; ++i) {
            nums1[i]=ans[i];
        }
    }
};

// 排序 time O((m+n)log(m+n)) kong O(log(m+n))
class Solution2 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        copy(nums2.begin(),nums2.end(),nums1.begin()+m);
        sort(nums1.begin(),nums1.end());
    }
};



// 逆向双指针 time O(m+n) kong O(1)
class Solution3 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

        vector<int>::value_type cur;

        int right1=m-1;
        int right2=n-1;
        int tail = m + n - 1;


        while (right1>=0 || right2>=0){

            if(right1==-1){

                cur=nums2[right2--];
            }else if(right2==-1){
                cur=nums1[right1--];
            }else if(nums1[right1]>nums2[right2]){
                cur=nums1[right1--];

            }else{
                cur=nums2[right2--];

            }
            nums1[tail--]=cur;
        }
    }
};


class Solution4 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int pos=m+n-1;
        m--;
        n--;
        while (m>=0 && n>=0){
            nums1[pos--]=nums1[m] > nums2[n]? nums1[m--]: nums2[n--];
        }
        while (n>=0){

            nums1[pos--]=nums2[n--];
        }



    }
};


int main() {
    Solution go;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2{2, 5, 6};
    int n = 3;

    go.merge(nums1, m, nums2, n);

    return 0;
}
