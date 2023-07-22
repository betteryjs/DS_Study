#include <iostream>
#include <bits/stdc++.h>


using namespace std;




class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(),points.end(),[](
                const vector<int> &a, const vector<int> &b
                ){
            return a[1]<b[1];
        });
        int ans=1;
        int cut=points[0][1];
        for (int i = 1; i<points.size() ; ++i) {

            if(points[i][0]>cut){
                ans++;
                cut=points[i][1];
            }
        }
        return ans;


    }
};




int main() {



    vector<vector<int>> points={{10,16},{2,8},{1,6},{7,12}};
    Solution go;
    auto c=go.findMinArrowShots(points);
    cout << c<<endl;


    return 0;
}
