#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// @solution-sync:begin
// DFS
class Solution {


public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;

    }


    int dfs(vector<vector<int>> &grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }


};
// @solution-sync:end



// stack
class Solution2 {


public:

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {


                int cur=0;
                stack<int>stackI;
                stack<int>stackJ;
                stackI.push(i);
                stackJ.push(j);
                while (!stackI.empty()){
                    int cursor_i=stackI.top(),cursor_j=stackJ.top();
                    stackI.pop();
                    stackJ.pop();
                    if (cursor_i < 0 || cursor_j < 0 || cursor_i == grid.size() || cursor_j == grid[0].size() || grid[cursor_i][cursor_j] != 1) {
                        continue;
                    }
                    ++cur;
                    grid[cursor_i][cursor_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cursor_i + di[index], next_j = cursor_j + dj[index];
                        stackI.push(next_i);
                        stackJ.push(next_j);
                    }
                    ans=max(ans,cur);
                }


            }
        }
        return ans;

    }

};





class Solution3 {


public:

    int maxAreaOfIsland(vector<vector<int>> &grid) {

        if(grid.empty() || grid[0].empty()) return 0;
        int max_area=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                    max_area=max(max_area,dfs(grid,i,j));
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        return 1+ dfs(grid,r+1,c) +dfs(grid,r-1,c)+dfs(grid,r,c+1)+dfs(grid,r,c-1);



    }

};



int main() {
    vector<vector<int>> grid = {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

    auto solution = Solution2();
    auto result = solution.maxAreaOfIsland(grid);
    cout << result << endl;

    return 0;
}
