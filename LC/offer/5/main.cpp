#include <iostream>
#include <bits/stdc++.h>


using namespace std;
class Solution {
public:
    string replaceSpace(string s) {

        int count=0,len=s.length();

        for (const char &  c:s) {
            if(c==' '){
                count++;
            }
        }

        s.resize(len+2*count);


        for (int i = len-1,j=s.size()-1; i < j; i--,j--) {


            if(s[i]!=' '){

                s[j]=s[i];
            }else{
                s[j-2]='%';
                s[j-1]='2';
                s[j]='0';
                j-=2;


            }

            
        }
        return s;



    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
