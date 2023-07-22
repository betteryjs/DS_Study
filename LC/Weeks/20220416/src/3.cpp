//
// Created by yjs on 2022/4/16.
//
#include <bits/stdc++.h>

using namespace std;


class ATM {

    const int A[5] = {20, 50, 100, 200, 500};
    vector<long long> cnt;

public:
    ATM() {
        // init cnt
        cnt = vector<long long>(5);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            cnt[i] += banknotesCount[i];
        }

    }

    vector<int> withdraw(int amount) {
        // exp amount = 600


        vector<long long> tmp(cnt.size());


        for (int i = (int) cnt.size() - 1; i >= 0; i--) {
            long long t = min(1LL * amount / A[i], cnt[i]);
            tmp[i] = t;
            amount -= t * A[i];
        }
        if (amount) return vector<int>{-1};
        for (int i = 0; i < tmp.size(); i++) cnt[i] -= tmp[i];
        // res=tmp
        vector<int> ret;
        for (long long x: tmp) ret.push_back(x);
        return ret;
    }
};


/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

int main() {


}