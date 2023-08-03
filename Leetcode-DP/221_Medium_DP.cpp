#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 暴力，从大到小遍历
        // int max_edge=min(matrix.size(),matrix[0].size());
        // while(max_edge>0){
        //     for(int i=0; i<matrix.size()-max_edge+1; i++){
        //         for(int j=0; j<matrix[0].size()-max_edge+1; j++){
        //             bool isFlag=true;
        //             for(int a=0; a<max_edge && isFlag; a++){
        //                 for(int b=0; b<max_edge && isFlag; b++){
        //                     if(matrix[i+a][j+b]=='0'){
        //                         isFlag=false;
        //                     }
        //                 }
        //             }
        //             if(isFlag){
        //                 return max_edge*max_edge;
        //             }
        //         }
        //     }
        //     max_edge--;
        // }
        // return max_edge*max_edge;

        // dp
        // 这道题的状态转移方程比较难想到
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        int max_edge=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1;
                    max_edge=max(max_edge,dp[i][j]);
                }
                if(i>0 && j>0 && matrix[i][j]=='1'){
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    max_edge=max(max_edge,dp[i][j]);
                }
            }
        }
        return max_edge*max_edge;
    }
};