#include <iostream>
#include <bits/stdc++.h>


using namespace std;




class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char,int> need,window;
        vector<int> res;


        for (const char & c:p) {
            need[c]++;
        }

        int left=0,right=0;
        int valid=0;
        while (right<s.size()){

            char c=s[right];
            right++;

            if(need.count(c)){
                window[c]++;
                if(need[c]==window[c]){

                    valid++;

                }
            }


            while (right-left+1>p.size()){

                if(valid==need.size()){
                    res.push_back(left);
                }
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d]){

                        valid--;

                    }
                    window[d]--;
                }





            }




        }
        return res;



    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
