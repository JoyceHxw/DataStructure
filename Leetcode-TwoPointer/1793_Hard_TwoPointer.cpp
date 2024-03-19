// 给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。
// 一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1) 。一个 好 子数组的两个端点下标需要满足 i <= k <= j 。
// 请你返回 好 子数组的最大可能 分数 。

#include <iostream>
using namespace std;
#include <vector>


// 刚开始想到了从中间向两边移动的方法，但是没有想到维护最小值
// 类似于接雨水的题
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int left=k-1;
        int right=k+1;
        int ans=0;
        //i表示left到right的最小值
        //指针分别向左和向右移动，维护这个最小值
        for(int i=nums[k];;i--){
            while(left>=0 && nums[left]>=i){
                left--;
            }
            while(right<n && nums[right]>=i){
                right++;
            }
            ans=max(ans,(right-left-1)*i);
            if(left==-1 && right==n){
                break;
            }
        }
        return ans;
    }
};