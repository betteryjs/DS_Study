#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int num:nums) {
            if(num>0){
                hashset.emplace(num);
            }
        }
        return hashset.size();
    }
};
