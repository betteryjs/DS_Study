//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> newMatrix=matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                newMatrix[j][n-i-1]=matrix[i][j];
            }
        }
        matrix=newMatrix;



    }
};


int main() {

    return 0;
}