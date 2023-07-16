// 给你一个下标从 0 开始的整数数组 nums 和一个 非负 整数 k 。
// 在一步操作中，你可以执行下述指令：
// 在范围 [0, nums.length - 1] 中选择一个 此前没有选过 的下标 i 。
// 将 nums[i] 替换为范围 [nums[i] - k, nums[i] + k] 内的任一整数。
// 数组的 美丽值 定义为数组中由相等元素组成的最长子序列的长度。
// 对数组 nums 执行上述操作任意次后，返回数组可能取得的 最大 美丽值。
// 注意：你 只 能对每个下标执行 一次 此操作。
// 数组的 子序列 定义是：经由原数组删除一些元素（也可能不删除）得到的一个新数组，且在此过程中剩余元素的顺序不发生改变。
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // 我的解法：暴力遍历，超出时间限制
        // int n=nums.size();
        // vector<int> lower(n);
        // vector<int> upper(n);
        // int min_num=INT_MAX;
        // int max_num=INT_MIN;
        // for(int i=0; i<n; i++){
        //     lower[i]=nums[i]-k;
        //     min_num=min(min_num,nums[i]);
        //     upper[i]=nums[i]+k;
        //     max_num=max(max_num,nums[i]);
        //     // cout<<lower[i]<<" "<<upper[i]<<endl;
        // }
        // if(min_num==max_num){
        //     return n;
        // }
        // int ans=0;
        // for(int i=min_num; i<max_num; i++){
        //     int cnt=0;
        //     for(int j=0; j<n; j++){
        //         if(i>=lower[j] && i<=upper[j]){
        //             cnt++;
        //         }
        //     }
        //     ans=max(ans,cnt);
        // }
        // return ans;

        // 优化：数组排序
        // 注意思路转换
        // 数组排序后，问题转换成最大值减最小值的差不超过2k
        sort(nums.begin(), nums.end());
        int ans=0;
        // 遍历左右界限，仍然超时
        // for(int right=0; right<nums.size(); right++){
        //     int left=0;
        //     while(left<right && nums[right]-nums[left]>2*k){
        //         left++;
        //     }
        //     ans=max(ans,right-left+1);
        // }
        // 优化：left不用从0开始，right右移使差值增大
        int left=0;
        for(int right=0; right<nums.size(); right++){
            while(left<right && nums[right]-nums[left]>2*k){
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};