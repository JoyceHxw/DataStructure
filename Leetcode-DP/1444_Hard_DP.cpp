#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        // 以右下角为切入点，考虑苹果数量和切割方式的动态转移方程
        int m=pizza.size();
        int n=pizza[0].size();
        int mod=1e9+7;
        vector<vector<int>> apples(m+1,vector<int>(n+1));
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        
        // 右下角苹果数量
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){  
                apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
                dp[1][i][j] = apples[i][j] > 0;
            }
        }

        for (int ki = 2; ki <= k; ki++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // 水平方向切
                    for (int i2 = i + 1; i2 < m; i2++) {
                        if (apples[i][j] > apples[i2][j]) { // 表示切下来的两块都有苹果
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
                        }
                    }
                    // 垂直方向切
                    for (int j2 = j + 1; j2 < n; j2++) {
                        if (apples[i][j] > apples[i][j2]) {
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
                        }
                    }
                }
            }
        }
        return dp[k][0][0];


    }
};