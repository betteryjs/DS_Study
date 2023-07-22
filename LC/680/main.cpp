#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    // 双指针
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;


        while (left < right) {

            char c1 = s[left], c2 = s[right];

            if (c1 == c2) {
                left++;
                right--;
            } else {
                return checkPalindrome(s, left, right - 1) || checkPalindrome(s, left + 1, right);
            }
        }
    }


    bool checkPalindrome(const string &string1, const int &low, const int &height) {
        for (int i = low, j = height; i < j; ++i, --j) {
            if (string1[i] != string1[j]) {
                return false;
            }
        }
        return true;
    }
};
// @solution-sync:end

int main() {
    string s = "aba";

    auto solution = Solution();
    auto result = solution.validPalindrome(s);
    cout << result << endl;

    return 0;
}
