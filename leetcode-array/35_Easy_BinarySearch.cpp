#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 我的解法: 按序查找
        // int i=0;
        // int n=nums.size();
        // while(i<n && nums[i]<target){
        //     i++;
        // }
        // return i;   

        // 答案: 二分查找
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};