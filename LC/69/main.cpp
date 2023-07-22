#include <iostream>

using namespace std;

// @solution-sync:begin
// 二分法
class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return x;
        }
        int left=1,right=x,mid,ans=-1;

        while (left<=right){

            mid=left+(right-left)/2;
            if((long long)mid*mid<x){
                ans=mid;
                left=mid+1;
            } else{

                right=mid-1;
            }
        }
        return ans;
    }
};
// @solution-sync:end

int main() {
    int x = 4;

    auto solution = Solution();
    auto result = solution.mySqrt(x);
    cout << result << endl;

    return 0;
}
