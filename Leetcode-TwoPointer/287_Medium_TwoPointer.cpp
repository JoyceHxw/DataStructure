#include <iostream>
using namespace std;
#include <vector>


// 根本没想到环
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 排序
        // sort(nums.begin(),nums.end());
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1]){
        //         return nums[i];
        //     }
        // }
        // return 0;

        // 可能不止重复两次
        // n,n+1种可能
        // 二分法
        // int n=nums.size();
        // int l=1; int r=n-1;
        // int ans=0;
        // while(l<=r){
        //     int mid=(l+r)/2;
        //     int cnt=0;
        //     for(int i=0; i<n; i++){
        //         cnt+=(nums[i]<=mid);
        //     }
        //     // 重复的数大于i
        //     if(cnt<=mid){
        //         l=mid+1;
        //     }
        //     else{
        //         r=mid-1;
        //         ans=mid;
        //     }
        // }
        // return ans;

        // 快慢指针
        // a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c)
        int slow=0;
        int fast=0;
        slow=nums[slow]; //走一步
        fast=nums[nums[fast]]; //走两步
        // 找到相遇点
        while(slow!=fast){
            slow=nums[slow]; //走一步
            fast=nums[nums[fast]]; //走两步
        }
        // 找到环的起始位置
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};