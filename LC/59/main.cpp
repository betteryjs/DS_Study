#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n ,vector<int>(n));
        int upper_bound=0,lower_bound=n-1;
        int left_bound=0,right_bound=n-1;
        int number=1;
        while (number< n*n){
            if(upper_bound<=lower_bound){

                for (int i = left_bound; i <=right_bound ; ++i) {
                    matrix[upper_bound][i]=number++;
                }
                upper_bound++;

            }
            if(left_bound<=right_bound){
                for (int i = upper_bound; i <=lower_bound ; ++i) {
                    matrix[i][right_bound]=number++;
                }
                right_bound--;
            }
            if(upper_bound<=lower_bound){

                for (int i = right_bound; i >=left_bound ; --i) {
                    matrix[lower_bound][i]=number++;
                }
                lower_bound--;
            }
            if(left_bound<=right_bound){

                for (int i = lower_bound; i >=upper_bound ; --i) {
                    matrix[i][left_bound]=number++;

                }
                left_bound++;
            }







            }

        return matrix;








    }
};

int main() {
    Solution go;
    go.generateMatrix(3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
