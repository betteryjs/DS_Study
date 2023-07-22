//
// Created by yjs on 2022/2/1.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](
                const vector<int> &a,const vector<int> &b
        ){
            return a[1]<b[1];
        });


        int remote=0,prev= intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0]<prev){
                remote++;

            }else{

                prev=intervals[i][1];
            }

        }
        return remote;

    }
};
int main() {

    return 0;
}