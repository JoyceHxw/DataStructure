// 给你一个下标从 0 开始长度为 n 的数组 nums 。
// 每一秒，你可以对数组执行以下操作：
// 对于范围在 [0, n - 1] 内的每一个下标 i ，将 nums[i] 替换成 nums[i] ，nums[(i - 1 + n) % n] 或者 nums[(i + 1) % n] 三者之一。
// 注意，所有元素会被同时替换。
// 请你返回将数组 nums 中所有元素变成相等元素所需要的 最少 秒数。

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>


// 开始想的是贪心算法，但发现存在局部性，不能求得最优值
// 然后考虑暴力算法超时
// 然后考虑优化，不需要每一秒遍历来求值，可以根据位置计算得到
// 最后时间剩的不多了，暴力遍历所有两个位置组合的情况，没有想到只用考虑相同元素的相邻位置
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        //贪心算法，找能同化身边的元素最多的，不成立，存在局限
        //还要找尽量分散的
        
        //暴力
//         int min_seconds=nums.size();
//         for(auto max_num: nums){
//             vector<bool> v(nums.size());
//             int cnt=nums.size();
//             for(int i=0; i<v.size(); i++){
//                 if(nums[i]==max_num){
//                     v[i]=1;
//                     cnt--;
//                 }
//             }
//             int seconds=0;
//             vector<bool>temp=v;
//             while(cnt>0){
//                 for(int i=0; i<nums.size(); i++){
//                     if(v[i]==0){
//                         if((i>0 && temp[i-1]==1) || (i<nums.size()-1 && temp[i+1]==1) || (i==0 && temp[nums.size()-1]==1) || (i==nums.size()-1 && temp[0]==1 )){
//                             v[i]=1;
//                             cnt--;
//                         }
//                     }
//                 }
//                 seconds++;
//                 temp=v;
//             }
//             min_seconds=min(min_seconds,seconds);
//         }
//         return min_seconds;
        
        //不用遍历来确定操作次数，根据位置
        unordered_map<int,vector<int>> m;
        unordered_set<int> s;
        for(int i=0; i<2*nums.size(); i++){
            m[nums[i%nums.size()]].push_back(i);
            s.insert(nums[i%nums.size()]);
        }
        unordered_set<int>:: iterator iter=s.begin();
        int min_seconds=nums.size();
        while(iter!=s.end()){
            vector<int> temp=m[*iter];
            int max_seconds=0;
            bool isflag=false;
            for(int i=0; i<temp.size()-1; i++){
               //只考察相邻位置即可（差一点，没想到这）
                max_seconds=max(max_seconds,(temp[i+1]-temp[i])/2);
            }
            min_seconds=min(max_seconds,min_seconds);
            iter++;
        }
        return min_seconds;
    }
};