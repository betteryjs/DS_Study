#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:

    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){

            return false;
        }
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);
        int sum=0;
        for(int i=0;i<s.size();++i){
            cnt1[s[i]-'a']++;
            cnt2[goal[i]-'a']++;
            if(s[i]!=goal[i]){
                sum++;
            }

        }
        bool flag= false;
        for(int i=0;i<26;++i){
            if(cnt1[i]!=cnt2[i]){

                return false;
            }
            if (cnt1[i] > 1){
                flag = true;
            }
        }
        return sum==2|| (sum==0 && flag);
    }
};
int main() {
    Solution go;
    string s1("aa");
    string s2("aa");
    auto  res=go.buddyStrings(s1,s2);
    cout<< res<<endl;
    return 0;
}
