#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


// unordered_map
class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        unordered_map<int, int> countMap;
        for (const int &c: arr) {
            countMap[c]++;

        }
        int needLen = arr.size() / 4;
        for (auto[res, count]: countMap) {

            if (count > needLen) {
                return res;
            }

        }
        return -1;


    }
};


//
class Solution2 {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();

        int cur = arr[0], cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == cur) {
                ++cnt;
                if (cnt * 4 > n) {
                    return cur;
                }


            } else {

                cur=arr[i];
                cnt=1;

            }


        }
        return -1;


    }
};


// 摩尔投票法
class Solution3 {
public:
    int findSpecialInteger(vector<int> &arr) {
       int x=0,votes=0;
        for (const int & num:arr) {
            if(votes==0){

                x=num;

            }
            votes+=num==x?1:-1;
        }
        // x is max;
        int count=0;
        for (const int & num:arr) {

            if(num==x){
                count++;
            }



        }
        if(count*4>arr.size()){


            return x;
        }else{
            return -1;
        }




    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
