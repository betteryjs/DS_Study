#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {

    }
};
// @solution-sync:end

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
    vector<vector<int>> grid = {
            {1,  1,  1,  -1, -1},
            {1,  1,  1,  -1, -1},
            {-1, -1, -1, 1,  1},
            {1,  1,  1,  1,  -1},
            {-1, -1, -1, -1, -1}
    };

    auto solution = Solution();
    auto result = solution.findBall(grid);
    cout << toString(result) << endl;

    return 0;
}
