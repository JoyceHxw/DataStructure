// 给你一个下标从 0 开始的整数数组 nums 和一个整数 x 。
// 请你找到数组中下标距离至少为 x 的两个元素的 差值绝对值 的 最小值 。
// 换言之，请你找到两个下标 i 和 j ，满足 abs(i - j) >= x 且 abs(nums[i] - nums[j]) 的值最小。
// 请你返回一个整数，表示下标距离至少为 x 的两个元素之间的差值绝对值的 最小值 。

#include <iostream>
using namespace std;
#include <vector>
#include <set>

// 这道题有想到右边的加入，其可能的左边的能组合的数也加一个
// 但是没想到维护有序数组来优化，也不知道lower_bound

// 做了一个月的周赛了，还是只能做出前两题。。。
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        // 暴力超时
        // ans=inf
        // for i in range(len(nums)-x):
        //     for j in range(i+x,len(nums)):
        //         ans=min(ans,abs(nums[i]-nums[j]))
        // return ans

        // 有序集合优化
        int ans=INT_MAX;
        int n=nums.size();
        // 使用INT_MIN / 2作为哨兵的目的是将其设置为一个足够小的值，足以保证它小于任何可能出现的元素值，但又避免了INT_MIN本身可能引发的问题。这样做可以确保lower_bound在所有情况下都能正确工作，包括边界情况。
        set<int> s={INT_MIN/2, INT_MAX};
        for(int i=x; i<n; i++){
            // 随着i后移，不断插入之前可能与之组合的数
            s.insert(nums[i-x]);
            int y=nums[i];
            // 查找第一个不小于y的元素的迭代器it。
            auto it=s.lower_bound(y);
            // 只用比较相邻两个数与其的差
            ans=min(ans,min(*it-y,y-*--it));
        }
        return ans;
    }
};