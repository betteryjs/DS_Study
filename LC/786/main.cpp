#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int,int>> tmp;
        int nums=arr.size();
        for(int i=0;i<nums-1;++i) {
            for (int j = i + 1; j < nums; ++j) {
                tmp.emplace_back(arr[i], arr[j]);
            }
        }
        sort(tmp.begin(),tmp.end(),[&](const pair<int,int> & a , const pair<int,int> & b){
            return a.first * b.second < a.second * b.first;
        });


        for_each(tmp.begin(),tmp.end(),[](auto x){cout << x.first<< " "<< x.second<< " ";});
        cout<< endl;
        return {tmp[k-1].first,tmp[k-1].second};

    }
};

int main() {
    Solution go;
    vector<int>arr{1,2,3,5};
    int k=3;
    auto res=go.kthSmallestPrimeFraction(arr,k);

    for_each(res.begin(),res.end(),[](auto x){cout << x<< " ";});
    return 0;
}
