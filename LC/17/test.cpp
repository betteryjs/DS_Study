//
// Created by yjs on 2022/2/20.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    string c{"123456"};

    cout<< c.substr(0,c.size()-1)<<endl;

    vector<string>b{"saa","asfasfa","asfsafffffffffffff"};
    b.erase(b.begin());
    for (auto c:b) {
        cout << c<< " ";
    }

    return 0;
}