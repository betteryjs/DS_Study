#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> countMap;
        vector<char> keys;
        if (s.empty()) {
            return ' ';
        }
        for (const char &c: s) {
            if (countMap.find(c) == countMap.end()) {
                keys.push_back(c);
            }
            countMap[c] = countMap.find(c) == countMap.end();
        }
        for (const char &c: keys) {
            if (countMap[c]) {
                return c;
            }
        }
        return ' ';
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
