#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// 我们可以将区间 [0,N) 看做一个数组，然后将 blacklist 中的元素移到数组的最末尾，同时用一个哈希表进行映射：
class Solution {
private:
    int sz;
    unordered_map<int, int> mapping;
public:
    Solution(int n, vector<int> &blacklist) {
        // n=7 [0,6] [1,2,6]
        sz = n - blacklist.size();


        for (const int &b: blacklist) {
            mapping[b] = INT_MAX;
        }


        int last = n - 1;
        for (const int &b: blacklist) {
            if(b>=sz){
                continue;
            }

            while (mapping.count(last)) {
                last--;
            }

            mapping[b] = last;
            last--;
        }


    }

    int pick() {
        // 随机选取一个索引
        int index = rand() % sz;
        // 这个索引命中了黑名单，
        // 需要被映射到其他位置
        if (mapping.count(index)) {
            return mapping[index];
        }
        // 若没命中黑名单，则直接返回
        return index;
    }
};


class Solution2 {
private:

    int N;
    vector<int> blacklist;
public:
    Solution2(int n, vector<int> &blacklist) {
        sort(blacklist.begin(), blacklist.end());
        this->blacklist = blacklist;
        this->N = n;


    }

    int pick() {
        int res = rand() % N;
        while (exists(this->blacklist, res)) {
            // 重新随机一个结果
            res = rand() % N;
        }
        return res;
    }

    bool exists(const vector<int> &nums, const int &target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;

            } else if (nums[mid] > target) {

                right = mid - 1;
            }


        }
        return false;


    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
int main() {
    vector<int> blacklist{2, 3, 5};
    Solution2 * obj = new Solution2(7, blacklist);

    for (int i = 0; i < 20; ++i) {
        cout <<obj->pick()<<endl;
    }
    return 0;
}
