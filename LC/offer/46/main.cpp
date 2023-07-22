#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int translateNum(int num) {
        string stringNum = to_string(num);
        int n = stringNum.size();
        int dp[n];
        int a = 1, b = 1, c; // a=dp[i-1] b=dp[i-2]  b  ---> a ----> c

        for (int i = 2; i <= n; i++) {
            string tmp = stringNum.substr(i - 2, 2);
            if (tmp >= "10" && tmp <= "25") {
                c = a + b;
            } else {
                c = a;
            }
            b = a;
            a = c;
        }
        return a;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
