// 给你一个整数 n 表示数轴上的房屋数量，编号从 0 到 n - 1 。
// 另给你一个二维整数数组 offers ，其中 offers[i] = [starti, endi, goldi] 表示第 i 个买家想要以 goldi 枚金币的价格购买从 starti 到 endi 的所有房屋。
// 作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。
// 返回你可以赚取的金币的最大数目。
// 注意 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 第一次周赛做出第3题！
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // 动态规划
        // dp[i]为到i位置售出房屋的最大收益
        vector<int> dp(n,0);
        // 按结束位置排序
        sort(offers.begin(), offers.end(), [](const vector<int>& v1, const vector<int>& v2){return v1[1]<v2[1];});
        // for(auto offer: offers){
        //     cout<<offer[0]<<" "<<offer[1]<<" "<<offer[2]<<endl;
        // }
        int max_num=0;
        for(auto offer: offers){
            int i=offer[0]-1;
            // 存在start-1房屋未售出的情况
            while(i>=0 && dp[i]==0){
                i--;
            }
            // 卖或不卖两种情况
            // 卖：start前最大收益+offer[2]
            // 不卖：持续之前最大收益
            if(i<0){
                dp[offer[1]]=max(max_num,offer[2]);
            }
            else{
                dp[offer[1]]=max(max_num,dp[i]+offer[2]);
                
            }
            max_num=max(max_num,dp[offer[1]]);
        }
        return max_num;
    }
};