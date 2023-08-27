// 给你一个下标从 0 开始的数组 nums ，它包含 非负 整数，且全部为 2 的幂，同时给你一个整数 target 。

// 一次操作中，你必须对数组做以下修改：

// 选择数组中一个元素 nums[i] ，满足 nums[i] > 1 。
// 将 nums[i] 从数组中删除。
// 在 nums 的 末尾 添加 两个 数，值都为 nums[i] / 2 。
// 你的目标是让 nums 的一个 子序列 的元素和等于 target ，请你返回达成这一目标的 最少操作次数 。如果无法得到这样的子序列，请你返回 -1 。

// 数组中一个 子序列 是通过删除原数组中一些元素，并且不改变剩余元素顺序得到的剩余数组。

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 这道题在做的时候，想到了应该从位运算入手，但是没想出来应该如何凑出target
// 这道题的切入点：位运算，关于2次方幂的和的定理，递减排序
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sm=0;
        for(int x: nums){
            sm+=x;
        }
        if(sm<target){
            return -1;
        }
        // 前提：target可以被认为是由2^i组成，i为二进制上是1的位数
        // 如果 nums 中比 2^p 小的数之和大于等于 2^p，一定存在一种方案用它们凑出一个2^p（归纳法证明） 

        // 逆序排列，方便从小到大考虑
        sort(nums.begin(),nums.end(),[](int a, int b){return a>b;});
        int ans=0;
        // 计算比当前二进制位小的所有数之和
        long long t=0;
        for(int i=0; i<=30; i++){
            // 从低位到高位检查target二进制为1表示的数是否能从nums中凑出
            if(target>>i&1){
                int x=1<<i;
                // 把比当前二进制位小的数加到t中
                while(!nums.empty() && nums.back()<x && t<x){
                    t+=nums.back();
                    nums.pop_back();
                }

                if(t>=x){
                    // 表示比当前二进制位小的数之和已经大于等于当前二进制位，这一位可以从nums中凑出，不再考虑
                    t-=x;
                }
                else if(nums.back()==x){
                    // 刚好找到需要的数，也不用操作
                    // 但继续保留t，使其凑成更高位的数
                    nums.pop_back();
                }
                else{
                    // 需要从高位分解获得
                    int y=nums.back();
                    nums.pop_back();
                    while(y>x){
                        y>>=1;
                        // push_back一个另一个要么等于x，被使用，要么大于x，要继续被拆，本次不会被添加到原有的数组中。
                        nums.push_back(y);  // 保持递减序列
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};