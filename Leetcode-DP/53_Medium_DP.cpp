#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 不是有序数列，无法用双指针或滑动窗口
        // 暴力超出时间限制
        // int ans=nums[0];
        // int i=0;
        // while(i<nums.size()){
        //     int s=nums[i];
        //     ans=max(ans,s);
        //     if(nums[i]<0){
        //         i++;
        //     }
        //     else{
        //         int j=i+1;
        //         while(j<nums.size()){
        //             s+=nums[j];
        //             if(nums[j]>0){
        //                 ans=max(ans,s);
        //             }
        //             j++;
        //         }
        //         i++;
        //     }
        // }
        // return ans;
        
        // 动态规划
        //保存以nums[i]结尾的连续子数组的最大值
        // 下一个值要么加入子数组，要么单独为组
        vector<int>f(nums.size(),nums[0]);
        int i=1;
        int ans=nums[0];
        while(i<nums.size()){ 
            f[i]=max(nums[i]+f[i-1],nums[i]);
            ans=max(ans,f[i]);
            i++;
        }
        return ans;
    }
};