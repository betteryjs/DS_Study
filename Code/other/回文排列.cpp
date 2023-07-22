//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// unorder map
class Solution {
public:
    bool canPermutePalindrome(string s) {

        unordered_map<char,int>counts;

        for (const char &c: s) {
            ++counts[c];
        }
        int one_count=0;

        for (auto res:counts) {
            if(res.second%2==1){
                one_count++;
                if(one_count>1){
                    return false;
                }
            }

        }
        return true;





    }
};

// bucket
class Solution2 {
public:
    bool canPermutePalindrome(string s) {

       vector<int>counts(128,0);

        for (const char &c: s) {
            ++counts[static_cast<int>(c)];
        }
        int one_count=0;

        for (int i = 0; i <counts.size(); ++i) {
            if(counts[i]%2==1){
                one_count++;
            }

        }
        return one_count > 1 ? false:true;





    }
};
// xor
class Solution3 {
public:
    bool canPermutePalindrome(string s) {

        bitset<128> flags;
        for(auto ch : s){
            flags.flip(ch);
        }
        return flags.count() < 2; //出现奇数次的字符少于2个







    }
};



int main() {

    return 0;
}