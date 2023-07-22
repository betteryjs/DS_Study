//
// Created by yjs on 2022/4/16.
//


#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<int> dp;
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {


            // cost1  min cost2 max
            long long number=(total/cost2);
            long long count=0;
            for (long long i = 0; i <= number; ++i) {
                long long cost1_max_number=(total-(i*cost2))/cost1;
                count+=cost1_max_number+1;
            }
        return count;










    }
};

int main(){

    Solution go;
    go.waysToBuyPensPencils(20,10,5);
    return 0;
}