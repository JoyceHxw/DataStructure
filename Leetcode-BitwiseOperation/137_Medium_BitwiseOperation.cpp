#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> m;
        // for(int i=0; i<nums.size(); i++){
        //     m[nums[i]]++;
        // }
        // for(int i=0; i<nums.size(); i++){
        //     if(m[nums[i]]==1){
        //         return nums[i];
        //     }
        // }
        // return 0;
        
        // 由于非答案值出现三次，把每个数的每一位相加，和除以3得到答案
        int ans = 0;
        // 第几位
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num: nums) {
                // 与1得到第i位的值
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};