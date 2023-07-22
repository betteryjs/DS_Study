#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    // match
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> tmp(n);


        for(int i=0;i<k;++i){
            tmp[(i+k)%n]=tmp[i];

        }

        nums.assign(nums.begin(), nums.end());
        for(auto n:nums){
            cout<< n<< ' ';
        }


    }
};


class Solution2 {
public:
    // list
    void rotate(vector<int>& nums, int k) {
        list<int> n_list(nums.begin(),nums.end());


        for(int i=0;i<k;++i){
            auto tmp=n_list.back();
            n_list.pop_back();
            n_list.push_front(tmp);


        }


        nums.assign(n_list.begin(),n_list.end());

        for(auto n:nums){
            cout<< n<< ' ';
        }



    }
};


class Solution3 {
public:
    // list

    void reverse(vector<int>& nums,int start,int end){

        while (start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {


        k%=nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);


        for(auto n:nums){
            cout<< n<< ' ';
        }








    }
};

int main() {
    Solution3 go;
    vector<int>m{1,2,3,4,5,6,7};
    for_each(m.begin(), m.end(), [](auto n){cout<< n<< " ";});
    cout<< endl;
    int k=3;
    go.rotate(m,k);
    return 0;
}
