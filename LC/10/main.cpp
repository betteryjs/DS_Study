#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;

        int a = 1, b = 0;
        for (int i = 1; i < n; i++) {
            a = a + b;
            b = a - b;
            a %= 1000000007;
        }
        return a;
    }
};





class Solution2 {
public:

    int fib(int n) {
        int res = 0;
        if (n == 0) {

            return res;
        }
        if (n < 3) {
            res = 1;
            return res;
        } else {
            int a = 0, b = 1;
            int MOD = 1000000007;

            for (int i = 1; i < n; ++i) {
                int tmp = b;
                b = a + b;
                a = tmp;
                b %= 1000000007;

            }
            return b;
        }
    }
};


class Solution3 {
public :
    int fib(int n) {
        int a = 0, b = 1, sum;
        for (int i = 0; i < n; i++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};


class Solution4 {
private:
    const int MOD = 1000000007;

public :
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<vector<long>> q{{1, 1}, {1, 0}};
        vector<vector<long>> res = pow(q, n - 1);
        return res[0][0];


    }

    vector<vector<long>> pow(vector<vector<long>> &a, int n) {
                vector<vector<long>> ret{{1,0},{0,1}}; // 单位矩阵
//        while (n>0){
//
//            if(n&1) {
//                // 如果为奇数
//                ret=multiply(ret,a);
//            }
//            a = multiply(a, a);
//            n>>=1;
//        }
        for(int i=0;i<n;++i){
            ret = multiply(ret, a);
        }
        return ret;





    }


    vector<vector<long>> multiply(vector<vector<long>> &a, vector<vector<long>> &b) {
        vector<vector<long>> res{{0, 0},
                                 {0, 0}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j])%MOD;


            }
        }
        return res;


    }
};


int main() {

    Solution4 go;
    int n = 45;
    int res = go.fib(n);
    cout << res << endl;
    return 0;
}
