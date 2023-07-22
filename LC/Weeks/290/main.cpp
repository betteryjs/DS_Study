#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> countMap;
        vector<int> res;
        int len=nums.size();

        for (const vector<int> &  num:nums) {
            for (int c:num) {
                countMap[c]++;

            }
        }
        for (auto  [key,count]:countMap) {
            if(count==len){
                res.push_back(key);
            }
        }
        sort(res.begin(),res.end());
        return res;






    }
};















int main() {
    return 0;
}
