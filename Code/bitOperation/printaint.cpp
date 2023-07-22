//
// Created by yjs on 23-7-22.
//

#include <iostream>
#include <string>


using namespace std;


string pringInt( unsigned int & num){
    string  res{};
    for (int i = 31; i >=0 ; --i) {
        res+=(num&(1<<i))==0 ? "0": "1";
    }
    return res;
}


int main(){
    unsigned int c=16;
    cout << pringInt(c)<<endl;
    c|= 1<<5;
    cout << pringInt(c)<<endl;
    c^= 1<<1;
    cout << pringInt(c)<<endl;






    return 0;
}
