// 给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。
// 如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：
// 子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
// 子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
// 子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
// 如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。

#include <iostream>
using namespace std;
#include <vector>

//算是正式恢复打卡的第一天
//开始的思路是回溯，也顺利写出来了，但是超时
//复习动态规划
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        // int i=0;
        // return recursion(nums,i);
        int n=nums.size();
        vector<bool> f(n+1);
        f[0]=true;
        for(int i=1; i<=n; i++){
            bool f1=(i-2>=0 && nums[i-1]==nums[i-2]);
            bool f2=(i-3>=0 && nums[i-1]==nums[i-2] && nums[i-2]==nums[i-3]);
            bool f3=(i-3>=0 && nums[i-1]==nums[i-2]+1 && nums[i-2]==nums[i-3]+1);
            //注意f1和f2 f3写在前面
            f[i]=(f1 && f[i-2]) || ((f2||f3) && f[i-3]);
        }
        return f[n];
    }

    //回溯超出时间限制
    // bool recursion(vector<int>& nums, int i) {
    //     if (i == nums.size()) {
    //         return true;
    //     }
    //     if (i > nums.size() - 2) {
    //         return false;
    //     }
    //     if (nums[i] == nums[i + 1]) {
    //         i += 2;
    //         if (recursion(nums, i)) {
    //             return true;
    //         }
    //         i -= 2;
    //     }
    //     if (i > nums.size() - 3) {
    //         return false;
    //     }
    //     if ((nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) ||
    //         (nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])) {
    //         i += 3;
    //         if (recursion(nums, i)) {
    //             return true;
    //         }
    //         i -= 3;
    //     }
    //     return false;
    // }
};