#include <bits/stdc++.h>

using namespace std;


class Solution {
private:

public:
    string removeDuplicateLetters(string s) {

        stack<char> stackChar;
        unordered_map<char, int> countMap;
        for (const char &c: s) {
            countMap[c]++;

        }

        vector<bool> inStack(256, false);
        for (char c: s) {
            countMap[c]--;
            // 如果存在数组中 直接跳过

            if (inStack[c]) {
                continue;
            }
            while (!stackChar.empty() && stackChar.top() > c) {
                if (countMap[stackChar.top()] == 0) {
                    break;
                }
                inStack[stackChar.top()] = false;
                stackChar.pop();
            }
            stackChar.push(c);
            inStack[c] = true;
        }
        string res;
        while (!stackChar.empty()) {
            res.push_back(stackChar.top());
            stackChar.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;


    }
};


class Solution2 {
private:

public:
    string removeDuplicateLetters(string s) {
        // "bcabc"
        stack<char> stackChar;
        vector<bool> isInstack(256, false);
        unordered_map<char, int> countMap;
        for (const char &c: s) {

            countMap[c]++;
        }
        for (char &c: s) {
            countMap[c]--;
            if (isInstack[c]) {
                continue;
            }
            while (!stackChar.empty() && stackChar.top() > c) {
                if (countMap[stackChar.top()] == 0) {
                    break;
                }
                isInstack[stackChar.top()] = false;
                stackChar.pop();

            }
            stackChar.push(c);
            isInstack[c] = true;


        }
        string res;
        while (!stackChar.empty()) {

            res.push_back(stackChar.top());
            stackChar.pop();

        }
        reverse(res.begin(),res.end());
        return res;


    }


};


int main() {
    Solution2 go;

    auto res = go.removeDuplicateLetters("cbacdcbc");
    std::cout << res << std::endl;
    return 0;
}
