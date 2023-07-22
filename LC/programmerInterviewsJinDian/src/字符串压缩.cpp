//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        int i = 0, j = 0, ls = S.length();
        string res;
        while (i < ls) {
            while (j < ls && S[i] == S[j])
                j++;
            res += S[i];
            res += to_string(j - i);
            i = j;
        }

        return res.length() < ls ? res : S;
    }
};



int main() {
    Solution go;
    go.compressString("aabcccccaaa");

    return 0;
}