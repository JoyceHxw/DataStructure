#include <iostream>
using namespace std;
#include <vector>

// 打家劫舍，经典的动态规划问题
// 在之前的题的训练下，很顺利地自己做出来了！
class Solution {
public:
    int rob(vector<int>& nums) {
        // 动态规划
        // 上一个
        int last1=0;
        // 上上个
        int last2=0;
        for(int i=0; i<nums.size(); i++){
            int temp=last1;
            // 保留上一个答案，不加当前元素，或者选择上上个答案，加上当前元素
            last1=max(last2+nums[i],last1);
            last2=temp;
        }
        return max(last1,last2);
    }
};