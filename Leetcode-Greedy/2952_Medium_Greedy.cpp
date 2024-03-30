// 给你一个下标从 0 开始的整数数组 coins，表示可用的硬币的面值，以及一个整数 target 。
// 如果存在某个 coins 的子序列总和为 x，那么整数 x 就是一个 可取得的金额 。
// 返回需要添加到数组中的 任意面值 硬币的 最小数量 ，使范围 [1, target] 内的每个整数都属于 可取得的金额 。
// 数组的 子序列 是通过删除原始数组的一些（可能不删除）元素而形成的新的 非空 数组，删除过程不会改变剩余元素的相对位置。

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


// 完全没想到贪心的思路，在动态规划方向上思考，但没找到状态转移方程

// 贪心思路：
// 对于正整数 x，如果区间 [1,x−1] 内的所有金额都可取得，且 x 在数组中，则区间 [1,2x−1] 内的所有金额也都可取得。
// 如果区间 [1,x−1] 内的所有金额都可取得，则从贪心的角度考虑，添加 x 之后即可取得 x，且满足添加的金额个数最少。
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans=0;
        int x=1;
        int index=0;
        int n=coins.size();
        while(x<=target){
            if(index<n && coins[index]<=x){
                x+=coins[index];
                index++;
            }
            else{
                x*=2;
                ans++;
            }
        }
        return ans;
    }
};