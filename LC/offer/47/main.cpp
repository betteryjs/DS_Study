#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //  f(i, j)f(i,j) 为从棋盘左上角走至单元格 (i ,j)(i,j) 的礼物最大累计价值
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) continue;
                if(i == 0) {
                    grid[i][j] += grid[i][j - 1]; // dp
                }
                else if(j==0){
                    grid[i][j] += grid[i - 1][j];
                }else{
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
