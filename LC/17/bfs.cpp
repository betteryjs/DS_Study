#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:

    vector<string> result;
    string digits;
    unordered_map<char, string> store = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
    int digitsSize = int(this->digits.size());

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        this->digits = digits;
        //储存字典
        dfs("", 0);
        return result;
    }

    void dfs(string resultStr, int index) {

        if (digitsSize == index) {
            result.push_back(resultStr);
            return;
        }
        char targetChar = this->digits[index];
        string targetStr = store[targetChar];
        for (auto tmpChar: targetStr) {
            dfs(resultStr + tmpChar, index + 1);//递归调用
        }
        return;
    }
};

