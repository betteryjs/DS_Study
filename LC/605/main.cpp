#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int can = 0;
        vector<int>::size_type flow_long=flowerbed.size();


        for (int i = 0; i < flow_long ; ++i) {
            if (flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flow_long-1 || flowerbed[i+1]==0) ){

                can++;
                flowerbed[i] = 1;

            }
                // flowerbed[i]==0  当前位置没有花
                // i==0 || flowerbed[i-1]==0 前面要么没有花, 要么是边界
                // i==flow_long-1 || flowerbed[i+1]==0 后面要么没有花, 要么是边界
        }
        return can>=n;

        }

};
int main() {
    Solution gp;
    int n=2;
    vector<int>flowerbed{0,0,0,0,1};
    gp.canPlaceFlowers(flowerbed, n);
    return 0;
}
