#include <iostream>
using namespace std;
#include <vector>

// 关键在于发现父节点与子节点的路径和的关系
// 注意列表结构的树的遍历，需要先得到邻接节点
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // 邻居节点，包括父节点和子节点
        vector<vector<int>> neighbor(n);
        for(int i=0; i<edges.size(); i++){
            int x=edges[i][0];
            int y=edges[i][1];
            neighbor[x].push_back(y);
            neighbor[y].push_back(x);
        }
        //树的大小，起始包括本身，有1个节点
        vector<int> size(n,1);
        vector<int> ans(n);
        dfs_num(neighbor,0,-1,size,ans,0);
        //第二次dfs，计算路径
        dfs_dis(neighbor,0,-1,size,ans,n);
        return ans;
    }
    // 树的大小
    void dfs_num(vector<vector<int>>& neighbor,int node, int parent,vector<int>& size,vector<int>& ans, int depth){
        // 计算根节点到所有节点的路径和
        ans[0]+=depth;
        for(int i=0; i<neighbor[node].size(); i++){
            if(neighbor[node][i]!=parent){
                dfs_num(neighbor,neighbor[node][i],node,size,ans,depth+1);
                size[node]+=size[neighbor[node][i]];
            }
        }
    }
    void dfs_dis(vector<vector<int>>& neighbor,int node, int parent,vector<int>& size, vector<int>& ans, int& n){
        for(int i=0; i<neighbor[node].size(); i++){
            if(neighbor[node][i]!=parent){
                //当前节点的路径和，和父节点路径和的关系
                ans[neighbor[node][i]]=ans[node]+n-2*size[neighbor[node][i]];
                dfs_dis(neighbor,neighbor[node][i],node,size,ans,n);
            }
        }
    }
};