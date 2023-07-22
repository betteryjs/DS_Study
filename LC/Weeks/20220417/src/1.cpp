//
// Created by yjs on 2022/4/17.
//

#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string digitSum(string s, int k) {

        vector<string> res;   // 分组后的字符串
        res.push_back(s);
        // 拆分字符串
        while (getCount(res)>k){

            s="";
            for (string c : res) {
                s+=c;
            }
            cout << s<<endl;
            res.clear();
            int n = s.size();
            int curr = 0;   // 每个分组的起始下标
            while (curr < n) {
                string b=s.substr(curr, k);
                int sum=0;
                for (const  char &c : b) {
                    sum+=(c-'0');

                }
                res.push_back(to_string(sum));
                curr += k;
            }
        }

        string res2="";
        for (string c: res) {
            res2+=c;
        }
        cout << res2<<endl;

        return res2;
//        return "";
    }
    int getCount(const vector<string> & c){

        int sum=0;
        for (string c1:c) {
            sum+=(int)c1.size();

        }
        return sum;

    }

};



int main(){


    string c="11111222223";

    Solution go;
    go.digitSum(c,3);

    return 0;

}


