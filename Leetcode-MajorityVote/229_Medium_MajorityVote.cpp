#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // vector<int> ans;
        // int n=nums.size();
        // int threshold=n/3;
        // unordered_map<int,int> m;
        // unordered_map<int,bool> used;
        // for(int i=0; i<n; i++){
        //     m[nums[i]]++;
        //     if(m[nums[i]]>threshold && !used[nums[i]]){
        //         ans.push_back(nums[i]);
        //         used[nums[i]]=true;
        //     }
        // }
        // return ans;

        // 摩尔投票，不同元素之间相互抵消，剩下最多的元素
        // 最多剩下两个
        vector<int> ans;
        // 先随便设定两个最多的元素，后面再更新
        int element1=0;
        int element2=0;
        int vote1=0;
        int vote2=0;
        for(auto& num: nums){
            if(vote1>0 && num==element1){
                vote1++;
            }
            else if(vote2>0 && num==element2){
                vote2++;
            }
            // 更新元素
            else if(vote1==0){
                element1=num;
                vote1++;
            }
            else if(vote2==0){
                element2=num;
                vote2++;
            }
            // 不同元素抵消
            else{
                vote1--;
                vote2--;
            }
        }
        // 统计剩下最多的元素的个数
        int cnt1=0;
        int cnt2=0;
        for(auto& num:nums){
            if(vote1>0 && num==element1){
                cnt1++;
            }
            if(vote2>0 && num==element2){
                cnt2++;
            }
        }
        if(cnt1>nums.size()/3){
            ans.push_back(element1);
        }
        if(cnt2>nums.size()/3){
            ans.push_back(element2);
        }
        return ans;

    }
};