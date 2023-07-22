#include <iostream>
#include <bits//stdc++.h>


using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), [](
                const vector<int> &a, const vector<int> &b
        ) {
            if(a[0]!=b[0]){

                return a[0] > b[0];
            }else{
                return a[1]<b[1];
            }

        });

        for (int i = 0; i < people.size(); ++i) {
            if(ans.size()<=people[i][1]){

                ans.push_back(people[i]);
            }else {

                ans.insert(ans.begin()+people[i][1],people[i]);

            }
        }
        return ans;
    }
};

int main() {
    Solution go;
    vector<vector<int>> people{{7, 0},
                               {4, 4},
                               {7, 1},
                               {5, 0},
                               {6, 1},
                               {5, 2}};


    go.reconstructQueue(people);
    return 0;
}
