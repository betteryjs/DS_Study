#include <vector>
#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;

// @solution-sync:begin

class Solution {
public:
    int gcd(int a, int b) { // 欧几里得算法
        return b == 0 ? a : gcd(b, a % b);
    }

//    int gcd(int a, int b) { // 更相减损法
//        while (true) {
//            if (a > b) a -= b;
//            else if (a < b) b -= a;
//            else return a;
//        }
//    }




    vector<string> simplifiedFractions(int n) {

        // 最简分数
        // hashmap
        if(n==1){
            return vector<string>{};
        }
        vector<string> ans;


            for (int i = 1; i < n; ++i) {
                for (int j = i+1; j <=n ; ++j) {
                    // 分子 i 分母 j
                    if(gcd(i, j) == 1){
                        ans.push_back({to_string(i)+"/"+to_string(j)});
                    }

                }

            }



        return ans;
    }
};
// @solution-sync:end











#include <sstream>

string toString(vector<string> v) {
    stringstream out;
    out << "[";
    unsigned long size = v.size();
    for (int i = 0; i < size; ++i) {
        out << v[i];
        if (i < size - 1)
            out << ",";
    }
    out << "]";
    return out.str();
}

int main() {
    int n = 5;

    auto solution = Solution();
    auto result = solution.simplifiedFractions(n);
    cout << toString(result) << endl;

    return 0;
}