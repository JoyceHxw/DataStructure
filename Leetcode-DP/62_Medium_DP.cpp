#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    // DFS，自己写的！但超时
    // int ans=0;
    // int uniquePaths(int m, int n) {
    //     // int ans=0;
    //     step(m,n);
    //     return ans;
    // }
    // void step(int i, int j){
    //     // 到达终点
    //     if(i==1 && j==1){
    //         ans+=1;
    //         return;
    //     }
    //     if(i<1 || j<1){
    //         return; //剪枝
    //     }
    //     step(i-1,j);
    //     step(i,j-1);
    //     return;
    // }
    int uniquePaths(int m, int n) {
        // 动态规划，自己写的！
        // 到达下一个点的方法=左边的点的方法+上边的点的方法
        vector<int>t(n,0);
        vector<vector<int>> dp(m,t);
        // vector<vector<int>> f(m, vector<int>(n)); //初始化方法
        // 最左列和最上行都为1
        for(int i=0; i<n; i++){
            dp[0][i]=1;
        }
        for(int i=0; i<m; i++){
            dp[i][0]=1;
        }
        int i=1;
        while(i<m){
            int j=1;
            while(j<n){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                j++;
            }
            i++;
        }
        return dp[m-1][n-1];
    }
};