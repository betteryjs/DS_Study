//
// Created by yjs on 2022/1/6.
//


#include <iostream>
#include <vector>



using namespace std;



class Solution {
    // time O(n) space O(1)
public:
    int mod = 1e9+7;
    int fib(int n) {
        int a=0,b=1,sum;
        for (int i = 0; i < n; ++i) {
            sum=(a+b) % mod;
            a=b;
            b=sum;
        }
        return a;
    }
};


class Solution2 {
    static int cache[110];
public:
//    const static int count = 110;
    int mod = 1e9+7;
    int fib(int n){
        // fib(0)=0 fib(1)=1
        if(n<=1){
            return n;
        }
        if(cache[n]!=0){
            return cache[n];
        }
        cache[n]= fib(n-1)+ fib(n-2);
        cache[n]%=mod;
        return cache[n];
    }
};










class Solution3 {



public:
    static const int MOD = 1000000007;

    struct Matrix{

        static const int N=2;

        vector<vector<long>> matrix= vector<vector<long>>(N, vector<long>(N,0));

        Matrix() {

            matrix= vector<vector<long>>(N, vector<long>(N,0));

        }
        Matrix(const vector<vector<long>> &  m) {

            matrix=m;

        }
        void printMatrix() {

            for (int i = 0; i < N; ++ i) {
                for (int j = 0; j < N; ++ j) {
                    cout << this->matrix[i][j] << " ";
                }
                cout << endl;
            }

        }
        Matrix multiply(const Matrix & a, const Matrix & b) {
            Matrix ans;
            for (int i = 0; i <Matrix::N; ++ i) {
                for (int j = 0; j < Matrix::N; ++ j) {
                    for(int k = 0; k < Matrix::N; ++ k) {
                        ans.matrix[i][j] += (a.matrix[i][k] * b.matrix[k][j])% MOD;
                    }
                }
            }
            return ans;
        }
         Matrix qpow( Matrix x, int n) {
            Matrix res;
            for (int i = 0; i < Matrix::N; ++ i) {
                res.matrix[i][i] = 1;
            }
            while (n) {
                if (n & 1) res = multiply(res,x);
                x = multiply(x,x);
                n >>= 1;
            }
            return res;
        }
    };


    int fib(int n){
        if (n < 2) {
            return n;
        }
        Matrix a({{1,1},{1,0}});


        Matrix base;
        base.matrix[0][0] = 1;

        Matrix ans = ans.qpow(a, n - 1);
        ans = ans.multiply(ans , base);

        return ans.matrix[0][0];
    }
};

int main(){

    Solution3 go;

    int res= go.fib(25);


    cout<< res<<endl;
//    Matrix ans({{1,1},{1,2}});
//    ans.prt();
//    Matrix x({{1,0},{0,1}});
//    ans=Matrix::multiply(x,ans);
////    x.prt();





    return 0;

}