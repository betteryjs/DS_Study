#include <bits/stdc++.h>


using namespace std;


class Solution {
private:
    struct cmp {

        bool operator()(const pair<int, int> &n1, const pair<int, int> &n2) {
            return n1.second < n2.second;
        }
    };

public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {

        //升序排序 num1

        sort(nums1.begin(), nums1.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> priorityQueue;
        for (int i = 0; i < nums2.size(); ++i) {
            priorityQueue.push(pair<int, int>{i, nums2[i]});
        }
        //指向nums1最差的值
        int left = 0;
        //指向nums1最好的值
        int right = nums1.size() - 1;
        vector<int> res(nums2.size());

        while (!priorityQueue.empty()) {

            pair<int, int> a = priorityQueue.top();
            priorityQueue.pop();
            int index = a.first;
            //总是指向nums2中最好的值
            int num = a.second;

            //如果nums1中最好的值大于num
            if (nums1[right] > num) {
                //就用最大的值作为结果去跟num2比

                res[index] = nums1[right];
                right--;


            } else {

                res[index] = nums1[left];
                left++;


            }


        }
        return res;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
