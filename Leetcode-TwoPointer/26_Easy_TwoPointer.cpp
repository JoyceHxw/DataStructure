#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 我的解法: 暴力
        // int n=nums.size();
        // int cnt=1;
        // if (n==0){
        //     return 0;
        // }
        // for(int i=1; i<n; i++){
        //     int j=0;
        //     bool isShow=false;
        //     while(j<cnt){
        //         // cout<<"i="<<i<<endl;
        //         // cout<<"j="<<j<<endl;
        //         if(nums[i]==nums[j]){
        //             isShow=true;
        //             break;
        //         }
        //         j++;
        //     }
        //     if(isShow==false){
        //         nums[cnt]=nums[i];
        //         cnt++;
        //     }
        // }
        // return cnt;

        // 答案: 双指针(数组是有序的)
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};