#include <bits/stdc++.h>


using namespace std;





// 拓扑排序
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegrees(numCourses);
        vector<vector<int>> adjancecy(numCourses,vector<int>()); // 邻接链表
        queue<int> queue;
        for (const vector<int> & cp :prerequisites) {
            indegrees[cp[0]]++; // 入度+1
            adjancecy[cp[1]].push_back(cp[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if(indegrees[i]==0){
                queue.push(i);
            }
        }
        while (!queue.empty()){
            int pre=queue.front();
            queue.pop();
            numCourses--;
            for (const int cur : adjancecy[pre]) {
                if(--indegrees[cur]==0) queue.push(cur);


            }



        }
        return numCourses==0;




    }
};


// DFS
class Solution2 {
private:

    vector<vector<int>> adjancecy; // 邻接链表

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjancecy.resize(numCourses,vector<int>());
        vector<int> indegrees(numCourses);
        vector<int> flags(numCourses);
        for (const vector<int> & cp :prerequisites) {
            indegrees[cp[0]]++; // 入度+1
            adjancecy[cp[1]].push_back(cp[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            // 判断每个起步的节点是否有环
            if(!dfs(flags,i)) return false;

        }
        return true;



    }

    bool dfs(vector<int> & flags,int i){
        if(flags[i]==1) return false; // 在这次DFS中节点已经被访问过
        if(flags[i]==-1) return true; // 节点已经被DFS访问过
        flags[i]=1;

        for (const int & num: adjancecy[i]) {
            if(!dfs(flags,num)) return false;

        }


        flags[i]=-1;
        return true;


    }

};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
