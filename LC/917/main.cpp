#include <iostream>
#include <stack>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    string reverseOnlyLetters(string & s) {




        int n=s.size();

        for (int i = 0,j=n-1; i <j; ) {
            while (i<j  && !isalpha(s[i])) i++;
            while (i<j  && !isalpha(s[j])) j--;
            if (i < j) {

                swap(s[i],s[j]);
                i++;
                j--;
            }


        }


//        string ans(s);


        return s;






    }
};
// @solution-sync:end

int main() {
    string s = "ab-cd";

    auto solution = Solution();
    auto result = solution.reverseOnlyLetters(s);
    cout << result << endl;

    return 0;
}