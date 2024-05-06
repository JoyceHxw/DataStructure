// 给你一个 n x n 的网格 grid ，代表一块樱桃地，每个格子由以下三种数字的一种来表示：

// 0 表示这个格子是空的，所以你可以穿过它。
// 1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
// -1 表示这个格子里有荆棘，挡着你的路。
// 请你统计并返回：在遵守下列规则的情况下，能摘到的最多樱桃数：

// 从位置 (0, 0) 出发，最后到达 (n - 1, n - 1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为 0 或者 1 的格子）；
// 当到达 (n - 1, n - 1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
// 当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为 0 ）；
// 如果在 (0, 0) 和 (n - 1, n - 1) 之间不存在一条可经过的路径，则无法摘到任何一个樱桃。

#include <iostream>
using namespace std;
#include <vector>


//能做一条路线的，没想到可以两条路线同时考虑
//巧妙地是将移动步数作为dp的一个变量，且可以根据步数就可以不用将纵坐标再作为变量了
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        //从左上角到右下角，当前这一步可以通过左边或上边达到
        //按行遍历
        int n=grid.size();
        // //从左上角到右下角
        // //记录路径
        // vector<vector<int>> dp(n,vector<int>(n,0));
        // vector<vector<string>> direction(n,vector<string>(n,"no"));
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(grid[i][j]==-1){
        //             continue;
        //         }
        //         int k=grid[i][j]==1?1:0;
        //         bool is_flag=true;
        //         int left=0;
        //         int up=0;
        //         if(j-1>=0 && grid[i][j-1]!=-1){
        //             left=grid[i][j-1];
        //             is_flag=false;
        //         }
        //         if(i-1>=0 && grid[i-1][j]!=-1){
        //             up=grid[i-1][j];
        //             is_flag=false;
        //         }
        //         if(!(i==0 && j==0) && is_flag){
        //             grid[i][j]=-1;
        //             continue;
        //         }
        //         if(left>=up){
        //             dp[i][j]=left+k;
        //             direction[i][j]="left";
        //         }
        //         else{
        //             dp[i][j]=up+k;
        //             direction[i][j]="up";
        //         }
                
        //     }
        // }
        // if(grid[n-1][n-1]==-1){
        //     return 0;
        // }
        // //更新剩余的果子
        // int i_t=n-1, j_t=n-1;
        // while(i_t>=0 && j_t>=0){
        //     grid[i_t][j_t]=0;
        //     if(direction[i_t][j_t]=="left"){
        //         j_t-=1;
        //     }
        //     else if(direction[i_t][j_t]=="up"){
        //         i_t-=1;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return dp[n-1][n-1];

        //只考虑一条路径有问题
        //同时考虑从左上角到右下角的两条路径，需要考虑不重复取
        // dp[k][x1][x2]，k表示移动总步数，x1表示第一个人的横坐标，x2表示第二个人的横坐标，纵坐标可以从总步数中得到确定
        vector<vector<vector<int>>> dp(n+n-1, vector<vector<int>>(n,vector<int>(n, INT_MIN)));
        //起点
        dp[0][0][0]=grid[0][0];
        for(int k=1; k<2*n-1; k++){
            //x1=max(k-n+1,0)是考虑纵坐标的最大值为n-1
            for(int x1=max(k-n+1,0);x1<=min(k,n-1);x1++){
                int y1=k-x1;
                if(grid[x1][y1]==-1){
                    continue;
                }
                //x2=x1是避免两条路径重复
                for(int x2=x1; x2<=min(k,n-1); x2++){
                    int y2=k-x2;
                    if(grid[x2][y2]==-1){
                        continue;
                    }
                    //都往右
                    int res=dp[k-1][x1][x2];
                    //往下，往右
                    if(x1>0){
                        res=max(res,dp[k-1][x1-1][x2]);
                    }
                    //往右，往下
                    if(x2>0){
                        res=max(res,dp[k-1][x1][x2-1]);
                    }
                    //都往下
                    if(x1>0 && x2>0){
                        res=max(res,dp[k-1][x1-1][x2-1]);
                    }
                    res+=grid[x1][y1];
                    //不重复再加上
                    if(x1!=x2){
                        res+=grid[x2][y2];
                    }
                    dp[k][x1][x2]=res;
                }
            }
        }
        return max(dp[2*n-2][n-1][n-1],0);
    }
};