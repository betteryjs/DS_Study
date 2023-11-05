//
// Created by yjs on 23-11-5.
//

#include <vector>
#include <queue>

using namespace std;



const int MAX_VERTEX_NUM = 20;   //图中顶点的最大数量

struct Node {
    int data;
    char *info;
};

struct MGraph {
    vector<vector<int>> edges;
    Node node[MAX_VERTEX_NUM];        //存储图中顶点数据
    int edgesCount, nodesCount;
};


struct ArcNode {
    int adjvex;                //存储边或弧，即另一端顶点在数组中的下标
    struct ArcNode *nextarc;//指向下一个结点
    int info;             //记录边或弧的其它信息
};
struct VNode {
    int data;          //顶点的数据域
    ArcNode *firstarc;//指向下一个结点
};//存储各链表首元结点的数组

struct ALGraph {
    VNode vertices[MAX_VERTEX_NUM];  //存储图的邻接表
    int nodesCount, edgesCount;               //记录图中顶点数以及边或弧数
};


ALGraph *MGraphToALGraph(MGraph graph) {


    //初始化邻接表
    ALGraph *alGraph = new ALGraph;
    alGraph->nodesCount = graph.nodesCount;
    alGraph->edgesCount = graph.edgesCount;
    for (int i = 0; i < graph.nodesCount; ++i) {
        alGraph->vertices[i].firstarc = nullptr;
    }

    for (int i = 0; i < graph.nodesCount; ++i) {
        for (int j = 0; j < graph.nodesCount; ++j) {
            if (graph.edges[i][j] != 0) {

                ArcNode *arcNode = new ArcNode;
                arcNode->adjvex = j;
                arcNode->info=graph.edges[i][j];
                // head insert
                arcNode->nextarc = alGraph->vertices[i].firstarc;
                alGraph->vertices[i].firstarc = arcNode;


            }


        }

    }


    return alGraph;


}



class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indegrees;
    // 存储拓扑排序序列
    vector<int> result;

public:
    // prerequisites = [[1,0],[2,0],[3,1],[3,2]]  有向图
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indegrees.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[0]].push_back(info[1]);
            ++indegrees[info[1]];
        }

        queue<int> q;
        // 将所有入度为 0 的节点放入队列中
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // 从队首取出一个节点
            int u = q.front();
            q.pop();
            // 放入答案中
            result.push_back(u);
            for (int v: edges[u]) {
                --indegrees[v];
                // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
                if (indegrees[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() != numCourses) {
            // 没有一个拓扑排序
            return {};
        }
        // 返回拓扑排序
        return result;
    }
};







