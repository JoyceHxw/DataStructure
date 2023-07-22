// 给你一个下标从 0 开始的整数数组 nums 和一个正整数 x 。
// 你 一开始 在数组的位置 0 处，你可以按照下述规则访问数组中的其他位置：
// 如果你当前在位置 i ，那么你可以移动到满足 i < j 的 任意 位置 j 。
// 对于你访问的位置 i ，你可以获得分数 nums[i] 。
// 如果你从位置 i 移动到位置 j 且 nums[i] 和 nums[j] 的 奇偶性 不同，那么你将失去分数 x 。
// 请你返回你能得到的 最大 得分之和。
// 注意 ，你一开始的分数为 nums[0] 。

#include <iostream>
using namespace std;
#include <vector>

// 动态规划问题还是没有找到感觉
// 想到了应该要区分奇偶，但没想到当前的取值取决于前面的取值
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        //注意默认值不是0是负数
        vector<long long> dp(2,INT_MIN);
        dp[nums[0]%2]=nums[0];
        for(int i=1; i<nums.size(); i++){
            int t=nums[i]%2;
            dp[t]=max(dp[t],dp[t^1]-x)+nums[i];
            cout<<dp[t]<<endl;
        }
        return dp[0]>dp[1]? dp[0]:dp[1];
    }
};