#include <map>

// @solution-sync:begin
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {

        sort(dictionary.begin(), dictionary.end(), [](const string &string1, const string &string2) {
            if(string1.size()==string2.size()){
                return string1<string2;
            }else {

                return string1.size()>string2.size();
            }

        });

        int n=s.size();
        for(const string & ss:dictionary){
            int m=ss.size();
            int i=0,j=0;
            while (i<n && j<m){

                if(s[i]==ss[j]){

                    j++;
                }
                i++;
            }
            if(j==m){
                return ss;
            }

        }











//        for (const auto &dicts: dictionary) {
//            if (Check(dicts, s)) {
//                return dicts;
//            }
//
//        }
        return "";

    }

//    bool Check(const string &string1, const string &string_remove) {
//        unordered_map<char, int> ch1, ch2;
//        for (const char &c: string1) {
//            ++ch1[c];
//        }
//        for (const char &c: string_remove) {
//            ++ch2[c];
//        }
//
//        for (const auto &p: ch1) {
//            if (ch2.find(p.first) == ch2.end()) {
//                return false;
//            }
//        }
//        return true;
//
//
//    }

};
// @solution-sync:end

int main() {
    string s = "aewfafwafjlwajflwajflwafj";
    vector<string> dictionary = { "apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};

    auto solution = Solution();
    auto result = solution.findLongestWord(s, dictionary);
    cout << result << endl;

    return 0;
}