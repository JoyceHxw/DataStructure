// 给你一个长度为 n 下标从 0 开始的整数数组 nums 。
// 我们想将下标进行分组，使得 [0, n - 1] 内所有下标 i 都 恰好 被分到其中一组。
// 如果以下条件成立，我们说这个分组方案是合法的：
// 对于每个组 g ，同一组内所有下标在 nums 中对应的数值都相等。
// 对于任意两个组 g1 和 g2 ，两个组中 下标数量 的 差值不超过 1 。
// 请你返回一个整数，表示得到一个合法分组方案的 最少 组数。

#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <vector>

//在思路上局限在怎么把个数最多的数组分解，而忽略了在整体上要求每个数组互相都只相差1
//从而可以枚举结果来求解
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        //数组个数只能差一个，意味着分成k个数的组，和k+1个数的组
        //而k只能比minK小
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        int k = min_element(cnt.begin(), cnt.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
        //枚举k
        //每一组都要分成k和k+1个数的组
        for (; ; k--) {
            int ans = 0;
            for (auto &[_, c] : cnt) {
                //无法分成k和k+1个数的组
                if (c / k < c % k) {
                    ans = 0;
                    break;
                }
                ans += (c + k) / (k + 1);
            }
            if (ans) {
                return ans;
            }
        }
    }
};