#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];

            }

        }
        matrix = matrix_new;

    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 水平反转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }

        // 对角线反转

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    }
};


class Solution3 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        // 先沿对角线镜像对称二维矩阵

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 然后反转二维矩阵的每一行

        for (vector<int> &mat: matrix) {
            reserve(mat);
        }


    }

    void reserve(vector<int> &nums) {
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }


    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
