#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// @solution-sync:begin
//
class Solution {
public:

    struct cmp {

        bool operator()(const pair<int, int> &pair1, const pair<int, int> &pair2) {
            return pair1.second < pair2.second;
        }

    };

    string frequencySort(string s) {
        unordered_map<char, int> counts;

        for (const char &c: s) {
            ++counts[c];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> priorityQueue;
        for (auto&[char_name, count]: counts) {
            priorityQueue.emplace(char_name, count);
        }
        string ans;
        while (!priorityQueue.empty()) {
            int c_number = priorityQueue.top().second;
            char c_name = priorityQueue.top().first;
            while (c_number--) {
                ans += c_name;
            }
            priorityQueue.pop();
        }
        return ans;
    }
};
// @solution-sync:end

// bucket sort
class Solution2 {
public:


    string frequencySort(string s) {
        unordered_map<char, int> counts;
        int max_count = 0;
        for (const char &c: s) {
            max_count = max(max_count, ++counts[c]);
        }

        vector<vector<char>> buckets(max_count + 1);

        for (const auto &p: counts) {
            buckets[p.second].push_back(p.first);
        }
        string ans;
        for (int i = max_count; i >=0  ; --i) {
            if(!buckets[i].empty()){
                for(const char  & c_name:buckets[i]){
                    int count=i;
                    while (count--){
                        ans+=c_name;
                    }
                }
            }


        }





            return ans;


    }
};


int main() {
    string s = "tree";

    auto solution = Solution2();
    auto result = solution.frequencySort(s);
    cout << result << endl;

    return 0;
}
