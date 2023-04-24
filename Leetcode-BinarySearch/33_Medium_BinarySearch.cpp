#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分查找
        // 找到旋转点
        int i=0;
        while(i<nums.size()-1 && nums[i]<nums[i+1]){
            i++;
        }
        // cout<<"i="<<i<<endl;
        if(nums[0]<target){
            // 在左边
            int left=0;
            int right=i;
            int mid;
            while(left<=right){
                mid=(right-left)/2+left;
                if(target>nums[mid]){
                    left=mid+1;
                }
                else if(target<nums[mid]){
                    right=mid-1;
                }
                else{
                    return mid;
                }
            }
            return -1;
        }
        else if(nums[0]>target){
            // 在右边
            int left=i+1;
            int right=nums.size()-1;
            int mid;
            while(left<=right){
                mid=(right-left)/2+left;
                if(target>nums[mid]){
                    left=mid+1;
                }
                else if(target<nums[mid]){
                    right=mid-1;
                }
                else{
                    return mid;
                }
            }
            return -1;
        }
        else{
            return 0;
        }
    }
};