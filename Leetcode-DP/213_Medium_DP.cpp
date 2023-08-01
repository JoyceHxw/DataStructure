#include <iostream>
using namespace std;
#include <vector>

// 打家劫舍2
// 对于分类讨论问题还要再熟悉，下一次快速想到
class Solution {
public:
    int rob(vector<int>& nums) {
        // 分为两种情况：偷1~n-1；偷2~n
        // 转换成首尾不相连的情况
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        int a1=rob_sub(nums,0,nums.size()-2);
        int a2=rob_sub(nums,1,nums.size()-1);
        return max(a1,a2); 
    }
    int rob_sub(vector<int>& nums, int start, int end){
        int last1=0;
        int last2=0;
        bool isFirst=true;
        for(int i=0; i<end-start+1; i++){
            int temp=last1;
            last1=max(last2+nums[start+i],last1);
            last2=temp;
        }
        return max(last1,last2);
    }
};