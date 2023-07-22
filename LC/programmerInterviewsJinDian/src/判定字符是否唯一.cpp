//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// xor
class Solution {
public:
    bool isUnique(string astr) {
        int dist=0;
        int now_pos=0;
        for(const char c:astr){
            dist=c-'a';  //得到26位的二进制数中要处理的位置
            // a & (1<<k) 用于判断a的第k位数字是0是1
            if(now_pos&(1<<dist)){//如果这个位置之前已经出现了1，即该字符已经出现过
                return false;
            }
            now_pos |= (1<<dist); //更新存在1的位置
        }
        return true;
    }
};

// set
class Solution2 {
public:
    bool isUnique(string astr) {
        set<char>st;
        for(auto c:astr){
            st.insert(c);
        }
        return st.size()==astr.size();


    }
};
// sort --> 遍历
class Solution3 {
public:
    bool isUnique(string astr) {
        if(astr.size()<=1){
            return true;
        }
        sort(astr.begin(),astr.end());
        int i=0,j=1;
        while(j!=astr.size()){
            if(astr[i]==astr[j]){
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
};


// hashmap
class Solution4 {
public:
    bool isUnique(string astr) {
        if(astr.size()<=1){
            return true;
        }
        unordered_map<char,int>mp;
        for(const char c:astr){
            if(mp.count(c)){
                return false;
            }
            mp[c]=1;
        }
        return true;
    }
};


int main() {

    return 0;
}