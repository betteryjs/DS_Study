//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// hash table
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        unordered_map<char, int> ch1;
        unordered_map<char, int> ch2;
        for (auto c1: s1) {
            ++ch1[c1];
        }
        for (auto c2: s2) {
            ++ch2[c2];
        }

        for (auto c: s1) {
            if (ch2[c] != ch1[c]) {
                return false;
            }
        }

        return true;
    }
};

// sort
class Solution2 {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
       vector<int> ch1(s1.begin(),s1.end());
       vector<int> ch2(s2.begin(),s2.end());
        sort(ch1.begin(),ch1.end());
        sort(ch2.begin(),ch2.end());

        return ch1==ch2;
    }
};

// bucket
class Solution3 {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
       vector<int> ch1(26,0);
       vector<int> ch2(26,0);
        for (const char & c:s1) {
            ++ch1[c-'a'];
        }
        for (const char & c:s2) {
            ++ch2[c-'a'];
        }


        for (int i = 0; i < ch1.size(); i++) {
            if (ch1[i] != ch2[i]) {
                return false;
            }
        }
        return true;


        
    }
};



int main() {

    Solution go;
    auto res=go.CheckPermutation("abb", "aab");
    cout << res<<endl;
    return 0;
}