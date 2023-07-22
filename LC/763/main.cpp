#include <iostream>

#include <bits/stdc++.h>

using namespace std;




class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        // 记录字符最后出现的位置
        unordered_map<char,int> map;
        for (int i = 0; i < s.size(); ++i) {
            map[s[i]]=i;
        }
        int start=0,end=0;
        for (int i = 0; i < s.size(); ++i) {

            end=max(end,map[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;

            }

        }
        return ans;
    }
};
int main() {

    Solution go;
    string S = "ababcbacadefegdehijhklij";
    go.partitionLabels(S);
    return 0;
}
