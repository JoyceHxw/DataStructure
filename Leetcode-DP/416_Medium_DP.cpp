// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

#include <iostream>
using namespace std;
#include <vector>

//构造和等于某个值的问题，背包问题，动态规划
//注意值是true/false
class Solution {
public:
    bool ans=false;
    bool canPartition(vector<int>& nums) {
        //数组和是确定的，找到一个子数组的和为一半
        //不能遍历所有集合，2^200太大
        //回溯，超时

        //动态规划<选取元素的范围，元素和>
        // dp[i][j]==0表示取第0到i范围的元素使得元素和为j是不可能的
        int n=nums.size();
        if(n<2){
            return false;
        }
        int maxNum=0;
        int target=0;
        for(int num: nums){
            target+=num;
            maxNum=max(maxNum,num);
        }
        if(target%2){
            return false;
        }
        target/=2;
        if(maxNum>target){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        dp[0][nums[0]]=1;
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                if(j>nums[i]){
                    //选或不选
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i]]; 
                }
                else{
                    //不能选
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
    void recursion(vector<int>& nums, int sum, int target, vector<int>& vis){
        if(sum==target){
            ans=true;
            return;
        }
        else if(sum>target){
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(vis[i]==0){
                vis[i]=1;
                recursion(nums,sum+nums[i],target,vis);
                vis[i]=0;
            }
        }
    }
};