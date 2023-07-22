#include <iostream>
#include <vector>
#include <complex>


using namespace std;




class Matrix {
private:
    static const int N=2;
public:
    vector<vector<long>> matrix;
    Matrix() {
        matrix.clear();
    }
    Matrix(const vector<vector<long>> &  m) {
        matrix=m;
    }
    Matrix multiply(const Matrix & a, const Matrix & b) {
        Matrix ans;
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                for(int k = 0; k < N; ++ k) {
                    ans.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                }
            }
        }
        return ans;
    }
    void prt() {
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix qpow( Matrix x, int n) {
        Matrix res;
        for (int i = 0; i < Matrix::N; ++ i) {
            res.matrix[i][i] = 1;
        }
        while (n) {
            if (n & 1) res = multiply(res ,x);
            x = multiply(x ,x);
            n >>= 1;
        }
        return res;
    }

};



int fib(int n) {
    Matrix a({{1,1},{1,0}});


    Matrix base;
    base.matrix[0][0] = 1;

    Matrix ans = qpow(a, n - 1);
    ans = ans * base;

    return ans.matrix[0][0];
}
//class Test{
//
//private:
//    const int N=2;
//    typedef vector<vector<long>> matrix;
//    const int MOD = 1000000007;
//
//public:
//
//    matrix multiply(matrix& a, matrix& b) {
//        matrix ans;
//        for (int i = 0; i < N; ++ i) {
//            for (int j = 0; j < N; ++ j) {
//                for(int k = 0; k < N; ++ k) {
//                    ans[i][j] += a[i][k] * b[k][j] ;
//                }
//            }
//        }
//        return ans;
//    }
//};
int main() {
    vector<vector<long>> ans{{1,1},{1,1}};
    Matrix matrix(ans);



    matrix.prt();

    return 0;
}
