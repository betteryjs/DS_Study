#include <iostream>
#include <valarray>

using namespace std;

// @solution-sync:begin
// sqrt
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int) b) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool judgeSquareSum(int c) {

        long left = 0;
        long right = static_cast<long>(sqrt(c));

        while (left <= right) {

            long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum > c) {

                right--;
            } else if (sum < c) {
                left--;
            }

        }
        return false;


    }
};


int main() {
    int c = 5;

    auto solution = Solution();
    auto result = solution.judgeSquareSum(c);
    cout << result << endl;

    return 0;
}
