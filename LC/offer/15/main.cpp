#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count=0;
        for (int i = 0; i < 32; ++i) {
            if(n& (1<<i)){
                count++;
            }
        }
        return count;


    }
};
// @solution-sync:end

int main() {
    int n = 1011;

    auto solution = Solution();
    auto result = solution.hammingWeight(n);
    cout << result << endl;

    return 0;
}