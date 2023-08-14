#include <iostream>
using namespace std;
#include <vector>

// 虽然感觉出现两次应该是这道题的切入点，但还是没想到位运算
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 线性时间复杂度
        // unordered_map<int,int> m;
        // for(auto num: nums){
        //     m[num]++;
        // }
        // vector<int> ans;
        // for(auto num: nums){
        //     if(m[num]==1){
        //         ans.push_back(num);
        //     }
        // }
        // return ans;

        // 常量空间
        // 位运算
        int xorsum=0;
        for(auto num:nums){
            xorsum ^= num; //出现两次的数字都被抵消掉
        }
        int lsb=(xorsum==INT_MIN)? xorsum:xorsum & (-xorsum); //取反，第一个1左边取反，右边不变，与运算得最右边的1
        int type1=0;
        int type2=0;
        for(auto num:nums){
            // 分成两类，就分出了只出现一次的元素
            // 出现两次的元素会抵消掉
            if(num & lsb){
                type1^=num;
            }
            else{
                type2^=num;
            }
        }
        return {type1,type2};
    }
};