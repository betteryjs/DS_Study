
//
// Created by yjs on 2022/4/16.
//

#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
private:
    // preSum 数组，专门记录以原点为顶点的矩阵的元素之和
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        preSum.resize(m + 1, vector<int>(n + 1));
        // preSum[0][0]=0
        for (int i = 1; i <=m ; ++i) {
            for (int j = 1; j <=n ; ++j) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i - 1][j - 1] - preSum[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];

    }
};







int main(){

    return 0;
}