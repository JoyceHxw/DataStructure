// 给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，其中 starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。
// 返回数轴上被车 任意部分 覆盖的整数点的数目。

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        //暴力，哈希
        // int ans=0;
        // unordered_set<int> s;
        // for(auto car: nums){
        //     for(int i=car[0];i<=car[1];i++){
        //         if(s.find(i)==s.end()){
        //             s.insert(i);
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        //差分数组
        //假设[0,102]范围上点的值原本都为0，对于每个car覆盖的点进行+1，最后统计大于0的点，即表示被覆盖的点
        //根据差分数组，对数组中的所有点都+1，可以转换为对第一个数+1，对最后一个后面的数-1，然后对数组求前缀和即得到该点上的值
        int diff[102]={0};
        for(auto& p: nums){
            diff[p[0]]++;
            diff[p[1]+1]--;
        }
        int ans=0;
        int s=0;
        for(int d: diff){
            s+=d;
            ans+= s>0;
        }
        return ans;
    }
};