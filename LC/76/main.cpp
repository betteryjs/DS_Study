#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

// 滑动窗口

class Solution {




public:
    unordered_map <char, int> ch1, ch2;
    bool check() {
        for (const auto &p: ch2) {
            if (ch1[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {

        for (const auto &c: t) {
            ++ch2[c];
        }

        int left=0,right=-1;
        int min_left=-1,len=s.length();

        while (right<int(s.size())){
            if(ch2.find(s[++right])!=ch2.end()){
                // s[++right] 在 string t 中
                ++ch1[s[right]];

            }
            while (check() && left<=right){
                if((right-left+1)<=len){
                    len=right-left+1;
                    min_left=left;
                }
                if(ch2.find(s[left])!=ch2.end()){
                    --ch1[s[left]];
                }
                ++left;

            }
        }

        return min_left == -1 ? string() : s.substr(min_left, len);
    }
};




class Solution2{

public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;

        for (const char &c:t) {
            need[c]++;
        }

        // 初始化窗 left right

        int left=0,right=0;

        // 包含匹配字符个数
        int valid=0;

        // 记录最小覆盖子串的起始索引及长度
        int start=0,len=INT_MAX;

        while (right<s.size()){

            // 开始滑动

            char c=s[right];
            right++;

            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }

            // window 中全部包含 need的字符
            // 判断左侧窗口是否要收缩
            while (valid==need.size()){

                if(right-left<len){
                    start=left;
                    len=right-left;
                }
                // d 是将移出窗口的字符
                char d = s[left];
                // 缩小窗口
                left++;
                // 进行窗口内数据的一系列更新
                if(need.count(d)){
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;


                }


            }

        }


        // 返回最小覆盖子串
        return len == INT_MAX ?
               "" : s.substr(start, len);




    }


};










int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    auto solution = Solution();
    auto result = solution.minWindow(s, t);
    cout << result << endl;

    return 0;
}
