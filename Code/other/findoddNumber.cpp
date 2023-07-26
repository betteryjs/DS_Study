//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class FindNumber{
public:

    int findOddNumber(const vector<int> & arr){
        int eor=0;
        for (const int & a:arr ) {
            eor^=a;
        }
        return eor;

    }
    vector<int> findOddTwoNumber(const vector<int> & arr){
        int eor=0;
        for (const int & a:arr ) {
            eor^=a;
        }
        // eor=a ^ b
        // eor !=0
        // eor 必然有一位是1
        int rightOne=eor &(~eor+1);
        int onlyOne=0;
        for (int  cur:arr) {
            if((cur & rightOne)==0){
                onlyOne^=cur;
            }
            
        }


        return  vector<int>{onlyOne,eor^onlyOne};





    }





    };

int main() {
    FindNumber findNumber;
    vector<int> num{9,1,2,6,6,9};
    vector<int> c=findNumber.findOddTwoNumber(num);
    for (auto b:c) {
        cout << b<< " "<<endl;
    }


    return 0;
}