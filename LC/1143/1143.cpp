//
// Created by yjs on 23-2-22.


#include <iostream>
#include <vector>
#include <limits>
#include <functional>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        int n = piles.size();

        for (int i = n - 2; i >= 0; i--) {
            piles[i] += piles[i + 1];
        }
        int cache[n][(n + 1) / 4 + 1];
        memset(cache, -1, sizeof(cache)); // -1 表示没有访问过

        function<int(int, int )>dfs=[&](int i, int m )-> int {
            if(i+m*2>=n) return piles[i];
            int &res = cache[i][m];
            if (res != -1) return res;
            int mn=INT_MAX;
            for (int x = 1; x <= m * 2; ++x)
                mn = min(mn, dfs(i + x, max(m, x)));
            return res = piles[i] - mn;





        };

        return dfs(0,1);


    }

};


int main() {


}


