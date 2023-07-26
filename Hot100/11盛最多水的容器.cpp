#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                ans = max(ans, (j - i) * min(height[i], height[j]));
            }
        }
        return ans;

    }
};

class Solution2 {
public:
    int maxArea(vector<int> &height) {
        int ans=0,i=0,j=height.size()-1;

        while (i<j){
            ans= height[i]< height[j] ? max(ans,(j-i)*height[i++]):max(ans,(j-i)*height[j--]);
        }



        return ans;


    }
};




int main() {
    return 0;
}