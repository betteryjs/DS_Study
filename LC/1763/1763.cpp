//
// Created by yjs on 2022/2/1.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans = "";
        string::size_type len = s.size();

        if (len < 2) {
            return ans;
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {

                if (j - i + 1 > ans.size() && check_substring(s.substr(i, j - i + 1))) {


                    ans = s.substr(i, j - i + 1);

                }
            }

        }
        return ans;

    }

    bool check_substring(string substring) {
        set<char> set;
        for (char c: substring) {
            set.insert(c);
        }
        for (char c: substring) {

            char a = tolower(c), b = toupper(c);
            if (set.find(a) == set.end() || set.find(b) == set.end()) {

                return false;
            }

        }
        return true;


    }
};







//将原问题拆解成子问题，如果某个字符在当前字符串中没有它对应的大写或小写字符，
// 它必不能构成答案中的一部分，答案只能在它左边或在它右边。
//我们返回该点左边或右边更长的答案即为答案。
//如果不存在这样的字符，说明原字符串本身就是美好字符串。



class Solution2{
public:
    string longestNiceSubstring(string s) {

        string::size_type len = s.size();

        if (len < 2) {
            return "";
        }


        for (int i = 0; i < s.size(); ++i) {

            char c = s[i];
            if (s.find(toupper(c)) == string::npos || s.find(tolower(c)) == string::npos) {
                return get_max(this->longestNiceSubstring(s.substr(0,i)),this->longestNiceSubstring(s.substr(i+1)));
            }
        }
        return s;


    }
    string   get_max(const string &  string1,const string &  string2){
        if(string1.size()>=string2.size()){

            return string1;
        }else {
            return string2;

        }
    }


};





// 滑动窗口+check
class Solution3 {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2){
            return "";
        }
        int left=0;
        int right=s.size();

        while (left<right){

            if(check_substring(s.substr(left,)))

        }






    }


    bool check_substring(string substring) {
        set<char> set;
        for (char c: substring) {
            set.insert(c);
        }
        for (char c: substring) {
            char a = tolower(c), b = toupper(c);
            if (set.find(a) == set.end() || set.find(b) == set.end()) {
                return false;
            }

        }
        return true;


    }
};



int main() {


    Solution2 go;
    string string1{"dDzeE"};
    auto res = go.longestNiceSubstring(string1);
    cout << res << endl;
    return 0;
}