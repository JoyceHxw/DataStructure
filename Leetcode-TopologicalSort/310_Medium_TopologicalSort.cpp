// 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
// 给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
// 可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
// 请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
// 树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
 

#include <iostream>
using namespace std;
#include <vector>
#include <queue>


//直接的方法很容易写出来，遍历每种根节点的树，求每种树的高度
//难以想到从外向内，从叶节点到根节点的逆向遍历思路
//拓扑排序的灵活应用
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> matrix(n, vector<int>());
        // vector<int> isVisited(n, 0);

        // for (int i = 0; i < n; i++) {
        //     matrix[i] = vector<int>();
        //     isVisited[i] = 0;
        // }
        // for (auto& edge : edges) {
        //     matrix[edge[0]].push_back(edge[1]);
        //     matrix[edge[1]].push_back(edge[0]);
        // }

        // vector<int> ans;
        // int minHeight = n;

        // for (int i = 0; i < n; i++) {
        //     int height = getHeight(i, matrix, isVisited);
        //     if (minHeight > height) {
        //         ans.clear();
        //         ans.push_back(i);
        //         minHeight = height;
        //     } else if (minHeight == height) {
        //         ans.push_back(i);
        //     }
        //     // 清空访问记录
        //     for (int k = 0; k < n; k++) {
        //         isVisited[k] = 0;
        //     }
        // }
        // return ans;

        //从外向内的思路，从出度为1的叶子节点开始，运用拓扑排序向内走
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (auto & edge : edges){
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                qu.emplace(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = qu.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (--degree[v] == 1) {
                        qu.emplace(v);
                    }
                }
            }
        }
        while (!qu.empty()) {
            ans.emplace_back(qu.front());
            qu.pop();
        }
        return ans;
    }

    //超时
    int getHeight(int root, vector<vector<int>>& matrix, vector<int>& isVisited) {
        int height = 0;
        isVisited[root] = 1;
        for (int node : matrix[root]) {
            if (isVisited[node] == 0) {
                height = max(height, getHeight(node, matrix, isVisited));
            }
        }
        return height + 1;
    }
};