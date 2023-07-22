#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int>& m, pair<int, int>& n){
            return m.second > n.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        for (auto& [num, count] : occurrences) {
            if(q.size()==k){
                if(q.top().second <count){
                    q.pop();
                    q.emplace(num,count);
                }
            }else{
                q.emplace(num,count);
            }

        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;


    }



};
// @solution-sync:end




// buckets sort
class Solution2 {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        int max_count=0;
        for (const int & num:nums) {
            max_count=max(max_count,++counts[num]);

        }
        // create buckets
        vector<vector<int>> buckets(max_count+1);

        for (const auto & p : counts) {

            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for (int i = max_count; i >=0 && ans.size()<k ; --i) {
            for(const int  & num:buckets[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    break;
                }

            }



            
        }

        return ans;








    }



};










#include <sstream>

string toString(vector<int> v) {
    stringstream out;
    out << "[";
    unsigned long size = v.size();
    for (int i = 0; i < size; ++i) {
        out << v[i];
        if (i < size - 1)
            out << ",";
    }
    out << "]";
    return out.str();
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    auto solution = Solution2();
    auto result = solution.topKFrequent(nums, k);
    cout << toString(result) << endl;

    return 0;
}