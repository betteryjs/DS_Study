//
// Created by yjs on 2022/4/24.
//
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) { return a[1] > b[1]; });


        int n = points.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0); // 0 - 1
        sort(ids.begin(), ids.end(), [&](int i, int j) { return points[i][1] > points[j][1]; });

        vector<int> ans(n), xs;

        for (int id:ids) {




        }






//        vector<double > len(rectangles.size(),0.0);
//
//        for (int i = 0; i < rectangles.size(); ++i) {
//            len[i]=rectangles[i][0]*rectangles[i][0]+rectangles[i][1]*rectangles[i][1];
//
//        }
//        sort(len.begin(),len.end());
//        for_each(len.begin(),len.end(),[](auto  c){cout << c<< " ";});
//        cout <<endl;
//        vector<int>res;
//        int sum;
//        for (int i = 0; i < points.size(); ++i) {
//            int len2=points[i][0]*points[i][0]+points[i][1]*points[i][1];
//            cout << len2<<endl;
//            sum=upper_bound(len.begin(),len.end(),len2)-len.begin();
//            res.push_back(sum);
//
//
//
//
//        }
//        cout << sum<<endl;
//        return res;


    }
};

int main(){

    vector<vector<int>> res={{1,2},{2,3},{2,5}};
    vector<vector<int>> pooint={{2,1}};
    Solution go;
    go.countRectangles(res,pooint);


}

