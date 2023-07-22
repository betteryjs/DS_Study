//
// Created by yjs on 2022/4/21.
//

#include <bits/stdc++.h>


using namespace std;

int main(){

    vector<int> nums2{1,55,65,589};
    sort(nums2.begin(),nums2.end(),[](const int & a,const int &b){
        return a>b;
    });
    for_each(nums2.begin(),nums2.end(),[](const int & c){cout << c<< " ";});
    cout <<endl;
    return 0;


}