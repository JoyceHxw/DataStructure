#include <iostream>
using namespace std;
#include <vector>
#include <queue>


//拓扑排序实现不难，但是这道题思路比较难想，从叶节点的角度出发，逐步收缩
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        //整体思路：通过拓扑排序收缩无根树
        int n=coins.size();
        vector<vector<int>> g(n); //邻接表
        vector<int> degree(n); //度
        for(auto& edge: edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        int rest=n; //节点数
        //删除无金币的叶子节点
        {
            queue<int>q;
            for(int i=0; i<n; i++){
                if(degree[i]==1 && !coins[i]){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int u=q.front();
                degree[u]--;
                q.pop();
                rest--;
                for(int v: g[u]){
                    degree[v]--;
                    if(degree[v]==1 && !coins[v]){
                        q.push(v);
                    }
                }
            }
        }

        //删除所有叶子节点，删除两次，得到最后的遍历范围
        {
            for(int _=0; _<2; ++_){
                queue<int> q;
                for(int i=0; i<n; i++){
                    if(degree[i]==1){
                        q.push(i);
                    }
                }
                while(!q.empty()){
                    int u=q.front();
                    degree[u]--;
                    q.pop();
                    rest--;
                    for(int v: g[u]){
                        degree[v]--;
                    }
                }
            }
        }
        return rest==0? 0:(rest-1)*2;

    }
};