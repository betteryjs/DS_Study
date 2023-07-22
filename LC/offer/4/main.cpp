#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int rows = matrix.size(), columns = matrix[0].size();

        int row = 0, column = columns - 1;

        while (row < rows && column >= 0) {
            int num = matrix[row][column];
            if (num == target) {

                return true;
            } else if (num > target) {

                column--;
            } else {
                row++;
            }


        }
        return false;


    }
};

int main() {
    vector<vector<int>> matrix{{-5}};
    Solution go;

    std::cout << go.findNumberIn2DArray(matrix,-5)<< std::endl;
    return 0;
}
