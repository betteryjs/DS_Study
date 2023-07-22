#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int max_len = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (map.size() < k) {
                map[s[i]]++;
            }
            while (map.size() > k) {

                if (--map[s[j]] == 0) {
                    map.erase(s[j]);
                }
                j++;
            }
            max_len = max(max_len, i - j + 1);
        }
        return max_len;


    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
