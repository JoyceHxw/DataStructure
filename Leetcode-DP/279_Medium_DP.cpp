#include <iostream>
using namespace std;
#include <vector>

// 很烦，动态规划还是没有思路
class Solution {
public:
    int numSquares(int n) {
        // 动态规划
        vector<int> f(n+1);
        for(int i=1; i<=n; i++){
            int minn=INT_MAX;
            for(int j=1; j*j<=i; j++){
                minn=min(minn,f[i-j*j]);
            }
            f[i]=minn+1;
        }
        return f[n];
    }
};