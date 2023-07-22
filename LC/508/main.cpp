#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
            int n=score.size();
            vector<string> ans(n);
            vector<pair<int,int>> si;
            for(int i=0;i<n;++i){
                si.emplace_back(score[i],i);
//                ans.emplace_back({score[i],i})
            }
            sort(si.rbegin(),si.rend());
            ans[si[0].second]="Gold Medal";
            if(n>1){
             ans[si[1].second]="Silver Medal";
            }
            if(n>2){
             ans[si[2].second]="Bronze Medal";
            }
            for(int i=3;i<n;++i){
                ans[si[i].second]=to_string(i+1);
            }

            return ans;
    }
};

int main() {
    Solution go;
    vector<int>nums{5,4,3,2,1};
    go.findRelativeRanks(nums);
    return 0;
}
