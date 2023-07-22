#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char ,int> need,window;
        for (const char & c:s1) {
            need[c]++;
        }

        int left=0,right=0;
        int valid=0;

        while (right<s2.size()){
            char c=s2[right];
            right++;
            // 进行窗口内数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }


            }
            // 判断左侧窗口是否要收缩
            while (right-left>=s1.size()){
                if(valid==need.size()){
                    return true;
                }
                char d=s2[left];
                left++;
                // 进行窗口内数据的一系列更新
                if(need.count(d)){
                    if(need[d]==window[d]){
                        valid--;
                    }
                    window[d]--;


                }




            }



        }
        return false;


    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
