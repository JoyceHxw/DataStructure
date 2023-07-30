// 给你一个由 正 整数组成的数组 nums 。
// 如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：
// 子数组中 不同 元素的数目等于整个数组不同元素的数目。
// 返回数组中 完全子数组 的数目。
// 子数组 是数组中的一个连续非空序列。

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <unordered_map>

// 暴力->滑动窗口，一步步优化
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // O(n^2) -> O(n)
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int cnt=s.size();
        unordered_map<int,int> m;
        int ans=0;
        int j=0;
        for(int i=0; i<=nums.size()-cnt; i++){
            // unordered_set<int> temp;
            while(j<nums.size() && m.size()<cnt){
                // temp.insert(nums[j]);
                m[nums[j]]++;
                j++;
                // if(m.size()>=cnt){
                    // 优化，不需要再继续加右边的数
                //     ans+=nums.size()-j;
                //     break;
                // }
            }
            if(m.size()==cnt){
                ans+=nums.size()-j+1;
            }
            // 再优化，下一次右节点也不用从左节点开始遍历
            if(m[nums[i]]==1){
                m.erase(nums[i]);
            }
            else{
                m[nums[i]]--;
            }
        }
        return ans;

    }
};