// 给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。
// 如果子数组中所有元素都相等，则认为子数组是一个 等值子数组 。注意，空数组是 等值子数组 。
// 从 nums 中删除最多 k 个元素后，返回可能的最长等值子数组的长度。
// 子数组 是数组中一个连续且可能为空的元素序列。

#include <iostream>
using namespace std;
#include <vector>

// 我的思路是用hash表计算每类元素中间间隔其他元素的个数（要删除元素的个数），然后找满足k的元素
// 但是忽略了同一元素部分位置连续的情况
// 答案思路是将元素坐标分类,然后在每一类中采用双指针,就遍历了所有的可能性
// 区间问题考虑双指针
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>> pos(n+1);
        for(int i=0; i<n; i++){
            // 要删除的左边的元素的个数
            pos[nums[i]].push_back(i-pos[nums[i]].size());
        }
        // 对于每类元素的坐标采用双指针
        for(auto& ps: pos){
            int left=0;
            for(int right=0; right<ps.size(); right++){
                while(ps[right]-ps[left]>k){
                    left++;
                }
                ans=max(ans,right-left+1);
            }
        }
        return ans;
    }
};