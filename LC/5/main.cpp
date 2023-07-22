#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            // 以 s[i] 为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);
            // res = longest(res, s1, s2)
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;

    }



    // 在 s 中寻找以 s[l] 和 s[r] 为中心的最长回文串
    string palindrome(string s, int l, int r) {
        // 防止索引越界
        while (l >= 0 && r < s.length()
               && s[l] == s[r]) {
            // 双指针，向两边展开
            l--; r++;
        }
        // 返回以 s[l] 和 s[r] 为中心的最长回文串
        // [l+1,r)
        return s.substr(l + 1, r-l-1);
    }




    bool isPalindrome(string s) {
        // 一左一右两个指针相向而行
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

};


int main() {
    return 0;
}
