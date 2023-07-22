//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {

        return s1.length()==s2.length() && (s1+s1).find(s2) != string::npos;



    }
};



int main() {

    return 0;
}