//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {

        int n1 = first.size(), n2 = second.size();
        if (abs(n1 - n2) > 1) {
            return false;
        }
        int doThing = 0;
        int p1 = 0, p2 = 0;
        while (p2 < n2 && p1<n1) {
            if (first[p1] == second[p2]) {
                p1++;
                p2++;
            }else{
                doThing++;
                if(n1>n2){
                    p1++;
                }else if(n1<n2){
                    p2++;
                }else{
                    p1++;
                    p2++;
                }
                if(doThing>=2 ){
                    return false;
                }


            }
        }

        return true;






    }
};





class Solution2 {
public:
    bool oneEditAway(string first, string second) {
        if (second.size() > first.size())
            return oneEditAway(second, first);
        // 始终让first 更长
        int n1=first.size(),n2=second.size();
        if (n1-n2 > 1) {
            return false;
        }

        int doThing = 0;
        int p1 = 0, p2 = 0;
        while (p1< n1 && p2<n2) {
            if (first[p1] == second[p2]) {
                p1++;
                p2++;
            }else{
                doThing++;
                if(n1==n2){
                    p1++;
                    p2++;
                }else{
                    p1++;
                }
                if(doThing>=2 ){
                    return false;
                }

            }
        }

        return true;






    }
};






int main() {
    Solution go;
    auto res=go.oneEditAway("teacher",
                            "beacher");
    cout << res<<endl;
    return 0;
}