#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 递归，转化成n-1，n-2
        // 超出时间限制
        // if(n==1){
        //     return 1;
        // }
        // else if(n==2){
        //     return 2;
        // }
        // else{
        //     return climbStairs(n-1)+climbStairs(n-2);
        // }

        // 动态规划
        int first=0;
        int second=1;
        int ans=0;
        for(int i=1; i<=n; i++){
            ans=(first+second);
            first=second;
            second=ans;
        }
        return ans;
    }
};