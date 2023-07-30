//
// Created by yjs on 23-7-26.
//
//
// Created by yjs on 23-7-26.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        unordered_map <string, vector<string>> unorderedMap;
        for (string &str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            unorderedMap[tmp].emplace_back(str);
        }
        vector <vector<string>> ans;
        for (auto it: unorderedMap) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};


class Solution2 {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        vector <vector<string>> ans;
        map <string, vector<string>> hashTable;

        for (auto str: strs) {
            string sts = string(26, '0');
            for (auto c: str) {
                ++sts[c - 'a'];
            }
            hashTable[sts].emplace_back(str);
        }
        for (auto it: hashTable) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};

int main() {

//    Solution solution2;
//    vector<int>nums{3,2,4};
//    auto res=solution2.twoSum(nums,6);
//    cout << res[0] << " "<< res[1]<< endl;


    return 0;
}