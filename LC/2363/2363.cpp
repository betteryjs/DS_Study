#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int> hashmap;
        for (auto it1:items1) {
            if(hashmap.find(it1[0])==hashmap.end()) hashmap.emplace(it1[0],it1[1]);
            else hashmap[it1[0]]+=it1[1];

        }
        for (auto it1:items2) {
            if(hashmap.find(it1[0])==hashmap.end()) hashmap.emplace(it1[0],it1[1]);
            else hashmap[it1[0]]+=it1[1];
        }
        vector<vector<int>> res;
        for (auto iter: hashmap) {
            res.push_back({iter.first,iter.second});

        }
        sort(res.begin(),res.end(),[](const vector<int> & a, const vector<int>  & b){return a[0]<b[0];});
        return res;



    }
};


class Solution2 {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> hashmap;
        for (auto it1:items1) {
            hashmap[it1[0]]+=it1[1];

        }
        for (auto it1:items2) {
            hashmap[it1[0]]+=it1[1];

        }
        vector<vector<int>> res;
        for (auto iter: hashmap) {
            res.push_back({iter.first,iter.second});

        }
        return res;



    }
};

int main(){

    Solution go;
    vector<vector<int>> item1{{1,1},{4,5},{3,8}};
    vector<vector<int>> item2{{3,1},{1,5}};
    go.mergeSimilarItems(item1,item2);



    return 0;
}