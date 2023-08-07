#include <iostream>
using namespace std;
#include <vector>

// 用了多种方法，切入点是前后缀！
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 数组往前移动一个轮次O(n^2)
        // vector<int> ans(nums.size(),1);
        // int i=1;
        // while(i<nums.size()){
        //     for(int j=0; j<nums.size(); j++){
        //         ans[j]*=nums[(j+i)%nums.size()];
        //     }
        //     i++;
        // }
        // return ans;

        // 回溯，还是多次遍历，每个位置分为乘和不乘两种情况
        // vector<int> ans(nums.size());
        // int result=1;
        // int pos=-1;
        // int cnt=1;
        // recursion(result,pos,cnt,0,nums,ans);
        // return ans;

        // 前后缀哈希表
        // vector<int> prefix(nums.size()+1,1);
        // int result=1;
        // for(int i=0; i<nums.size(); i++){
        //     result*=nums[i];
        //     prefix[i+1]=result;
        // }
        // vector<int> suffix(nums.size()+1,1);
        // int result2=1;
        // for(int i=0; i<nums.size(); i++){
        //     result2*=nums[nums.size()-i-1];
        //     suffix[i+1]=result2;
        // }
        // vector<int> ans(nums.size());
        // for(int i=0; i<nums.size(); i++){
        //     // cout<<prefix[i]<<" "<<suffix[nums.size()-i-1]<<endl;
        //     ans[i]=prefix[i]*suffix[nums.size()-i-1];
        // }
        // return ans;

        // 动态规划，分步骤进行前后缀，同时更新ans（乘积）
        // int length = nums.size();
        // vector<int> answer(length);
        // // answer[i] 表示索引 i 左侧所有元素的乘积
        // // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        // answer[0] = 1;
        // for (int i = 1; i < length; i++) {
        //     answer[i] = nums[i - 1] * answer[i - 1];
        // }
        // // R 为右侧所有元素的乘积
        // // 刚开始右边没有元素，所以 R = 1
        // int R = 1;
        // for (int i = length - 1; i >= 0; i--) {
        //     // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
        //     answer[i] = answer[i] * R;
        //     // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
        //     R *= nums[i];
        // }
        // return answer;

        // 双指针
        int n=nums.size();
        vector<int> ans(n,1);
        // 动态更新前后缀
        int left=1;
        int right=1;
        for(int i=0; i<n; i++){
            ans[i]*=left;
            ans[n-i-1]*=right;
            left*=nums[i];
            right*=nums[n-i-1];
        }
        return ans;
    }
    // void recursion(int result,int& pos,int& cnt,int i,vector<int>& nums,vector<int>& ans){
    //     if(i>=nums.size()){
    //         if(pos>=0){
    //             ans[pos]=result;
    //             cout<<result<<endl;
    //         }
    //         return;
    //     }

    //     if(cnt==0){
    //         result*=nums[i];
    //         recursion(result,pos,cnt,i+1,nums,ans);
    //     }
    //     else{
    //         cnt--;
    //         recursion(result,i,cnt,i+1,nums,ans);
    //         cnt++;
    //         result*=nums[i];
    //         recursion(result,pos,cnt,i+1,nums,ans);
    //     }
    // }
};