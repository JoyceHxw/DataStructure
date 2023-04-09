#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 超时
        // sort(nums.begin(), nums.end());
        // vector<vector<int>>v;
        // if(nums.size()<2){
        //     return v;
        // }
        // set<pair<int,int>>s;
        // // 第一个值
        // for(int i=0; i<nums.size()-2; i++){
        //     // 后两个值
        //     int left=i+1;
        //     int right=nums.size()-1;
        //     while(left<right){
        //         int remain=0-nums[i];
        //         if(nums[left]+nums[right]>remain){
        //             right--;
        //         }
        //         else if(nums[left]+nums[right]<remain){
        //             left++;
        //         }
        //         else{
        //             vector<int>t;
        //             t.push_back(nums[i]);
        //             t.push_back(nums[left]);
        //             t.push_back(nums[right]);
        //             pair<int,int>p(nums[i],nums[left]);
        //             set<pair<int,int>>::iterator pos=s.find(p);
        //             if(pos==s.end()){
        //                 v.push_back(t);
        //                 s.insert(p);
        //             }
        //             left++;
        //             right--;
        //         }
        //     }
        // }
        // return v;

        // 优化
        sort(nums.begin(), nums.end());
        vector<vector<int>>v;
        if(nums.size()<2){
            return v;
        }
        // 第一个值
        for(int i=0; i<nums.size()-2; i++){
            // 一样的就直接跳过
            if(i>=1 && nums[i]==nums[i-1]){
                continue;
            }
            // 后两个值
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                // 一样的就直接跳过
                if(left>i+1 && nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
                int remain=0-nums[i];
                if(nums[left]+nums[right]>remain){
                    right--;
                }
                else if(nums[left]+nums[right]<remain){
                    left++;
                }
                else{
                    vector<int>t;
                    t.push_back(nums[i]);
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    v.push_back(t);
                    left++;
                    right--;
                }
            }
        }
        return v;
    }
};