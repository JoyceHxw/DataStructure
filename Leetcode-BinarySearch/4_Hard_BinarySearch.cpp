#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 直接：合并两个数组找中间值
        // vector<int> nums(nums1.size()+nums2.size());
        // int p1=0;
        // int p2=0;
        // int p=0;
        // while(p1<nums1.size() && p2<nums2.size()){
        //     if(nums1[p1]<=nums2[p2]){
        //         nums[p]=nums1[p1];
        //         p1++;
        //     }
        //     else{
        //         nums[p]=nums2[p2];
        //         p2++;
        //     }
        //     p++;
        // }
        // while(p1<nums1.size()){
        //     nums[p]=nums1[p1];
        //     p++;
        //     p1++;
        // }
        // while(p2<nums2.size()){
        //     nums[p]=nums2[p2];
        //     p++;
        //     p2++;
        // }
        // if(nums.size()%2==0){
        //     return float((nums[nums.size()/2-1]+nums[nums.size()/2]))/2;
        // }
        // else{
        //     return nums[nums.size()/2];
        // }

        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
    
    // 只需找到第k个数，不需要关心之前的顺序
    // 比较两个数组的k/2-1位置（即第k/2个元素）的元素大小，每次剔除k/2的可能性
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k){
        int m=nums1.size();
        int n=nums2.size();
        int index1=0;
        int index2=0;
        while(true){
            // 退出循环的三个条件
            if(index1==m){
                return nums2[index2+k-1];
            }
            if(index2==n){
                return nums1[index1+k-1];
            }
            if(k==1){
                return min(nums1[index1],nums2[index2]);
            }

            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                // 剔除第一个数组newIndex1及之前的k/2个数
                // 更新起点
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};