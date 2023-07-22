#include <iostream>
#include <vector>
#include <complex>


using namespace std;


class Solution {
private:
    int MOD=1337;
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size() - 1);





    }
    int dfs(int a, vector<int> b, int u){
        if(u==-1){
            return 1;
        }
        return qpow(dfs(a, b, u - 1), 10) * qpow(a, b[u]) % MOD;



    }


    int qpow(int a, int b) {
        int ans = 1;
        a %= MOD;
        while (b != 0) {
            if ((b & 1) != 0) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }


};




class Test{

private:
    const int N=2;
    typedef vector<vector<long>> matrix;
    const int MOD = 1000000007;

public:

    matrix multiply(matrix& a, matrix& b) {
        matrix ans;
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                for(int k = 0; k < N; ++ k) {
                    ans[i][j] += a[i][k] * b[k][j] ;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution go;
    vector<int> p{4,3,3,8,5,2};
    go.superPow(2,p);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
