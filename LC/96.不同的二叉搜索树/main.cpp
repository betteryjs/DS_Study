#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int numTrees(int n) {
        return count(1, n);


    }

    // /
    int count(int left, int right) {

        if (left > right) {
            return 1;
        }

        int res = 0;

        for (int i = left; i <= right; ++i) {

            int leftCount = count(left, i - 1);
            int rightCount = count(i + 1, right);
            res += leftCount * rightCount;


        }
        return res;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
