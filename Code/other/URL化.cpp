//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Solution {
public:
    string replaceSpaces(string  S, int length) {
        S=S.substr(0,length);
        string  ans;
        for (const char &c:S) {
            if(c==' '){
                ans+=("%20");
            }else{
                ans.push_back(c);
            }
        }
        return ans;



    }
};
int main() {

    return 0;
}