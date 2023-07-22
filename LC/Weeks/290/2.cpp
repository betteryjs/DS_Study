//
// Created by yjs on 2022/4/24.
//

#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int countLatticePoints(vector<vector<int>> &circles) {
        long long sum = 0;
        for (const vector<int> &circle: circles) {
            sum += findOnePoint(circle);

        }

        //


        return sum;
    }

    long long findOnePoint(vector<int> circle) {
        long long sum = 1; // [x,y]
        int x = circle[0];
        int y = circle[1];
        int r = circle[2];

        sum += r * 4;

        int sum2 = (fmod(pow(2, 0.5) * r, r)) * 4;

        sum += sum2;

        return sum;


    }

};


class Solution2 {
public:
    int countLatticePoints(vector<vector<int>> &circles) {

        int x1 = 0, y1 = 0, x2 = 0, y2 = 0, res = 0;
        for (auto &circle: circles) {
            x1 = min(x1, circle[0] - circle[2]);
            y1 = min(x1, circle[1] - circle[2]);
            x2 = max(x2, circle[0] + circle[2]);
            y2 = max(y2, circle[1] + circle[2]);
        }

        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                for (auto &c: circles) {
                    int tmp =(i-c[0])*(i-c[0])-c[2]*c[2]+(j-c[1])*(j-c[1]);
                    if (tmp <= 0) {
                        res++;
                        break;
                    }

                }

            }

        }
        return res;


    }


};


int main() {

    vector<vector<int>> circles = {{2, 2, 2},
                                   {3, 4, 1}};
    Solution2 go;
    auto res = go.countLatticePoints(circles);
    cout << res << endl;


}