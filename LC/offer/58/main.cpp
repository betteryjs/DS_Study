#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
       string ans;
        for(int i = n; i < n + s.length(); i++)
            ans.push_back(s[i % s.length()]);
        return ans;




    }
};
int main() {

    string c="abcdefghijlmn";
    cout << c.substr(1)<<endl;
    int i=7;
    cout << c.substr(2,i-2+1)<<endl;


    return 0;
}
