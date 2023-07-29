#include <iostream>
using namespace std;
#include <vector>

// 岛屿问题，典型的图遍历问题
// 自己很顺利地做出来了！
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visit(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    visit[i][j]=false;
                }
                else{
                    visit[i][j]=true;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(visit[i][j]==false){
                    dfs(grid,visit,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit,int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visit[i][j]){
            return;
        }
        visit[i][j]=true;
        dfs(grid,visit,i-1,j);
        dfs(grid,visit,i+1,j);
        dfs(grid,visit,i,j+1);
        dfs(grid,visit,i,j-1);
    }
};