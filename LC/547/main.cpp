#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if(!visited[i]){
                dfs(isConnected,i,visited);
                ++count;
            }

        }
        return count;
    }


    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        visited[i]= true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if(isConnected[i][j]==1 && !visited[j]){
                dfs(isConnected,j,visited);
            }
        }




    }
};
// @solution-sync:end


class UnionFind {
private:
    vector<int> capital;
    int unionCount = 0; // 合并次数


public:
    UnionFind(int capitalSize) {
        capital.resize(capitalSize);
        // 初始化
        for (int i = 0; i < capitalSize; ++i) {
            capital[i] = i;

        }



    }

public:

    void  unionCapital(int x,int y){
        // 将 y 合并到 x 集合中
        int findX=findCapital(x);
        int findY=findCapital(y);
        if(findX!=findY){

            capital[findY]=findX;
            unionCount++;
        }

    }

    int findCapital(int x){
        if(capital[x]==x) return x;
        return findCapital(capital[x]);
    }

    int getUnionCount() const {
        return this->unionCount;
    }


};


class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        UnionFind * unionfind=new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(isConnected[i][j]==1){
                    unionfind->unionCapital(i,j);
                }

            }

        }
        return n-unionfind->getUnionCount();


    }



};


int main() {
    vector<vector<int>> isConnected = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
    };

    auto solution = Solution2();
    auto result = solution.findCircleNum(isConnected);
    cout << result << endl;

    return 0;
}
