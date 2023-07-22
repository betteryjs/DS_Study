#include <iostream>
#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m=matrix.size(),n=matrix[0].size();

        int upper_bound=0, lower_bound=m-1;
        int left_bound=0,right_bound=n-1;
        vector<int> res;
        while (res.size()<m*n){

            if(upper_bound<=lower_bound){

                for (int i = left_bound; i <=right_bound ; ++i) {
                    res.push_back(matrix[upper_bound][i]);
                }
                upper_bound++;
            }

            if(left_bound<=right_bound){


                for (int i = upper_bound ; i <=lower_bound; ++i) {
                    res.push_back(matrix[i][right_bound]);

                }
                right_bound--;


            }

            if (upper_bound <= lower_bound) {
                // 在底部从右向左遍历
                for (int j = right_bound; j >= left_bound; j--) {
                    res.push_back(matrix[lower_bound][j]);
                }
                // 下边界上移
                lower_bound--;
            }

            if (left_bound <= right_bound) {
                // 在左侧从下向上遍历
                for (int i = lower_bound; i >= upper_bound; i--) {
                    res.push_back(matrix[i][left_bound]);
                }
                // 左边界右移
                left_bound++;
            }





        }
        return res;



    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
